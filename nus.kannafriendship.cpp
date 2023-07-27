// GLALL

#include <iostream>
#include <set>

using namespace std;

// void print(set<pair<int, int> > segments) {
//     cout<<endl<<"SEGMENTS"<<endl;
//     set<pair<int, int> >::iterator itr;
//     for (itr = segments.begin(); itr != segments.end(); itr++) {
//         cout << "first: " << itr->first << " second: " << itr->second << endl;
//     }
//     cout<<endl;
// }

int main() {
    int N, Q;
    cin >> N >> Q;

    set<pair<int, int> > segments; // uncovered segments
    segments.insert(make_pair(1, N));

    for (size_t i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, e;
            cin >> s >> e;
            // place track
            set<pair<int, int> > tempSegments;
            set<pair<int, int> >::iterator itr;
            for (itr = segments.begin(); itr != segments.end(); itr++) {
                if (itr->first > e || itr->second < s) {
                    tempSegments.insert(*itr);
                } else {
                    // track covers segment entirely, remove segment
                    if (itr->first >= s && itr->second <= e) {
                        tempSegments.erase(make_pair(itr->first, itr->second));
                    }
                    // track is within segment entirely, replace segment with 2 segments
                    else if (itr->first < s && itr->second > e) {
                        pair<int, int> newSeg1 = make_pair(itr->first, s-1);
                        pair<int, int> newSeg2 = make_pair(e+1, itr->second);
                        tempSegments.erase(make_pair(itr->first, itr->second));
                        tempSegments.insert(newSeg1);
                        tempSegments.insert(newSeg2);
                    }
                    // track overlaps with segment (track starts before segment)
                    // 7 >= 2 && 10 > 4
                    else if (itr->first >= s && itr->second > e) {
                        pair<int, int> newSeg = make_pair(e+1, itr->second);
                        tempSegments.erase(make_pair(itr->first, itr->second));
                        tempSegments.insert(newSeg);
                    }
                    // track overlaps (track starts after)
                    else if (itr->first < s && itr->second <= e) {
                        pair<int, int> newSeg = make_pair(itr->first, s-1);
                        tempSegments.erase(make_pair(itr->first, itr->second));
                        tempSegments.insert(newSeg);
                    }
                }
            }
            segments = tempSegments;
            //print(segments);
        } else if (t == 2) {
            int count = 0;
            set<pair<int, int> >::iterator itr;
            for (itr = segments.begin(); itr != segments.end(); itr++) {
                count += itr->second-itr->first+1;
            }
            cout << N-count << endl;
        }
    }
}