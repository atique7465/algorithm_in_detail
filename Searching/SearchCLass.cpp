#include<bits/stdc++.h>

using namespace std;

class Search {
public:
    int linear(vector<int> &v, int value) {

        int len = v.size();

        for (int i = 0; i < len; i++) {
            if (v[i] == value) {
                return i;
            }
        }

        return -1;
    }

    /**
     * equivalent STL: binary_search(v.begin(), v.end(), value);
     */
    int binary(vector<int> &v, int value) {

        int lo = 0, hi = v.size() - 1, mid;

        while (lo <= hi) {
            mid = (lo + hi) / 2; /// mid = lo + (hi - lo) / 2; //to avoid sum size overflow
            if (v[mid] == value) {
                return mid;
            } else if (v[mid] > value) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return -1;
    }

    /**
     * equivalent STL: binary_search(v.begin(), v.end(), value);
     */
    int recursiveBinary(vector<int> &v, int lo, int hi, int value) {

        if (lo <= hi) {
            int mid = (lo + hi) / 2; /// mid = lo + (hi - lo) / 2; //to avoid sum size overflow

            if (v[mid] == value) {
                return mid;
            } else if (v[mid] > value) {
                return recursiveBinary(v, lo, mid - 1, value);
            } else {
                return recursiveBinary(v, mid + 1, hi, value);
            }
        }

        return -1;
    }

    /**
     *  returns index of the first element in the range [first,last) which has a value not less than '>=' ‘search val’
     *  equivalent STL: lower_bound(v.begin(), v.end(), value) - v.begin();
     *  lower_bound(arr, arr+n, value) - arr;
     *  lower_bound(arr+3, arr+11, value) - arr; | range: 4, 10
     */

    int lowerBound(vector<int> v, int value){
        
        int lo = 0, hi = v.size() - 1, ans = v.size();
        
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid] >= hi){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid+1;
            }
        }
        
        return ans;
    }

    int lowerBound_02(vector<int> &v, int value) {

        int lo = 0, hi = v.size(), mid;

        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (v[mid] >= value) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    /**
     * returns the index of first element in the range [first,last) which has a value greater than ‘search val’
     * returns the index where we need to insert a value >= ‘search val’
     *  equivalent STL: upper_bound(v.begin(), v.end(), value) - v.begin();
     *  upper_bound(arr, arr+n, value) - arr;
     *  upper_bound(arr+3, arr+11, value) - arr; | range: 4, 10
     */

    int upperBound(vector<int> v, int value){

        int lo = 0, hi = v.size() - 1, ans = v.size();

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(v[mid] > hi){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
     
    int upperBound_02(vector<int> &v, int value) {

        int lo = 0, hi = v.size(), mid;

        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (v[mid] > value) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
