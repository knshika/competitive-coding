#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

long mergeAndCount(vector<int> &arr, long l, long mid, long r)
{
    long n = mid - l + 1;
    long m = r - mid;
    vector<int> left(n);
    vector<int> right(m);

    for (long i = 0; i < n; i++)
    {
        left[i] = arr[l + i];
    }
    for (long j = 0; j < m; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    long i = 0, j = 0, k = l, swaps = 0;
    while (i < n && j < m)
    {
        if (left[i] > right[j])
        {
            arr[k++] = right[j++];
            swaps += (mid + 1) - (l + i);
        }
        else
        {
            arr[k++] = left[i++];
        }
    }
    while (i < n)
        arr[k++] = left[i++];
    while (j < m)
        arr[k++] = right[j++];

    return swaps;
}

long divideAndCount(vector<int> &arr, long l, long r)
{
    long count = 0;
    if (l < r)
    {
        long m = l + (r - l) / 2; //(r+l)/2

        // count from left array from mid
        count += divideAndCount(arr, l, m);
        // count from right array from mid
        count += divideAndCount(arr, m + 1, r);

        // count after mergeing both arrays;
        count += mergeAndCount(arr, l, m, r);
    }
    return count;
}

long countInversions(vector<int> arr)
{
    long n = arr.size();

    return divideAndCount(arr, 0, n - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
