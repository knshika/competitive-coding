#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

// void heapify(vector<double> &temp, int n, int i){
//     int largest=i;
//     int l=2*i + 1;
//     int r=2*i + 2;

//     if(l<n && temp[largest]<temp[l]){
//         largest=l;
//     }
//     if(r<n && temp[largest]<temp[r]){
//         largest=r;
//     }
//     if(largest!=i){
//         swap(temp[i],temp[largest]);
//         heapify(temp, n, largest);
//     }
// }

// void heapSort(vector<double> &temp , int n){

//     for(int i = (n/2) -1 ; i>=0; i--){
//         heapify(temp, n, i);
//     }
//     for(int i=n-1; i>0; i--){
//         swap(temp[0],temp[i]);
//         heapify(temp, i, 0);
//     }
// }

// vector<double> runningMedian(vector<int> a) {
//     vector<double> res;
//     vector<double> temp;
//     for(int i=0; i< a.size(); i++){
//         temp.push_back(double(a[i]));
//         int n=temp.size();
//         if(n>1) heapSort(temp,n);
//         if((n%2)!=0){
//             res.push_back((temp[n/2]));
//         }else{
//             res.push_back(((temp[n/2]+temp[(n/2)-1])/2.0));
//         }

//     }
//     return res;
// }

vector<double> runningMedian(vector<int> a)
{
    vector<double> res;
    priority_queue<double> left;                                   // give max element or increasing order arrange
    priority_queue<double, vector<double>, greater<double>> right; // give min element or decreasing order arrange
    double curr = 0;
    for (int i = 0; i < a.size(); i++)
    {
        double k = a[i];
        // left and right have equal elements (odd case)
        if (left.size() == right.size())
        {
            // curr median is smaller than curr element so median will lie in top of min heap
            if (k > curr)
            {
                right.push(k);
                curr = right.top();
            }
            // curr median is smaller than curr element so median will lie in top of max heap
            else
            {
                left.push(k);
                curr = left.top();
            }
        }
        // when left have more elements than right (even case)
        else if (left.size() > right.size())
        {
            // curr element is greater so must lie in right (min heap)
            if (k > curr)
            {
                right.push(k);
            }
            // curr element is less than curr median,  so x must lie in left , so move 1 element from left to right
            else
            {
                left.push(k);
                right.push(left.top());
                left.pop();
            }
            curr = (left.top() + right.top()) / 2.0;
        }
        // when right have more elements than left (even case)
        else
        {
            // curr element is greater than curr median,  so x must lie in right , so move 1 element from right to left
            if (k > curr)
            {
                right.push(k);
                left.push(right.top());
                right.pop();
            }
            // curr element is less so must lie in left (max heap)
            else
            {
                left.push(k);
            }
            curr = (left.top() + right.top()) / 2.0;
        }
        res.push_back(curr);
    }

    return res;
}

// vector<double> runningMedian(vector<int> a)
// {
//     vector<double> res;
//     vector<double> temp;
//     for (int i = 0; i < a.size(); i++)
//     {
//         temp.push_back(double(a[i]));
//         int n = temp.size();
//         if (n > 1)
//             heapSort(temp, n);
//         if ((n % 2) != 0)
//         {
//             double median = (temp[n / 2]);
//             res.push_back(median);
//         }
//         else
//         {
//             double median = ((temp[n / 2] + temp[(n / 2) - 1]) / 2.0);
//             res.push_back(median);
//         }
//     }
//     return res;
// }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++)
    {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << fixed << setprecision(1) << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
