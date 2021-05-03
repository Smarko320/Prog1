#include "std_lib_facilities.h"

class Less {
    double v;
public:
    Less(double vv) : v{vv} { }

    bool operator()(const double val) { return val < v; }
};

template<typename C> void print(const C& c, char sep = '\n')
{
    cout << "===================\n";

    for (const auto ele : c)
        cout << ele << sep;

    cout << '\n';
}

int main(){
    //1
    const string iname {"szamok.txt"};
    ifstream ifs {iname};
    if (!ifs) throw runtime_error("Nem lehet olvasni a fájból " + iname);

    vector<double> vd;
    for (double d; ifs >> d; )
        vd.push_back(d);
    //2
    print(vd);

    // 3
    vector<int> vi (vd.size());
    copy(vd.begin(), vd.end(), vi.begin());

    // 4
    for (int i = 0; i < vd.size(); ++i)
        cout << vd[i] << '\t' << vi[i] << '\n';

    // 5
    double double_sum = accumulate(vd.begin(), vd.end(), 0.0);

    std::cout << "SUM " << double_sum << '\n';

    // 6
    double diff_sum = inner_product(vd.begin(), vd.end(), vi.begin(), 0.0, plus<double>(), minus<double>());

    cout << "Difference "
              << diff_sum << '\n';

    // 7
    reverse(vd.begin(), vd.end());

    print(vd);

    // 8
    double vd_mean = double_sum / vd.size();

    cout << "Számtani közép (mean) " << vd_mean << '\n';

    // 9
    vector<double> vd2 (vd.size());

    auto it = copy_if(vd.begin(), vd.end(), vd2.begin(), Less(vd_mean));
    vd2.resize(distance(vd2.begin(), it));

    print(vd2);

    // 10
    sort(vd.begin(), vd.end());

    print(vd);
}

