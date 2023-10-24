#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl, std::vector;

using ull = unsigned long long;

vector<ull> Sieve(ull n)
{
    vector<bool> arr(n, 1);
    vector<ull> primes;
    arr[0] = arr[1] = 0;
    int operations = 0;
    for (int i = 4; i < n; i += 2)
    {
        arr[i] = 0;
        operations++;
    }
    primes.push_back(2);
    int count = 0;
    for (int i = 3; i < n; i++)
    {
        if (arr[i])
        {
            primes.push_back(i);
            count++;
            vector<ull>::iterator it = primes.begin();
            it++;
            while (it != primes.end())
            {
                int p = i * (*it);
                if (p > n)
                    break;
                for (int j = 1; (p * j) < n; j += 2 * count)
                {
                    arr[p * j] = 0;
                    operations++;
                    // cout<<p*j<<"+";
                }
                it++;
            }
        }
    }
    cout << operations << "+";
    return primes;
}

int main()
{
    cout << "Calculate primes in a given range" << endl;
    ull n;
    cout << "Enter a positive number: ";
    cin >> n;
    vector<ull> prime = Sieve(++n);
    // cout << "Prime numbers:";
    // for (vector<ull>::iterator i = prime.begin(); i != prime.end(); i++)
    // {
    //     cout << *i << ' ';
    // }

    return 0;
}
