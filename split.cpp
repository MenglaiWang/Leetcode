void split(const string s, const string delim, vector<string>& ret) {
    int last = 0;
    int index = s.find_first_of(delim, last);
    while (index != -1) {
        ret.push_back(s.substr(last, index - last));
        last = index + 1 ;
        index = s.find_first_of(delim, last);
    }
    if (last < s.size())
        ret.push_back(s.substr(last));
}