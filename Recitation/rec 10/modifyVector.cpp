
void modifyVector(vector<int>& v){
    int number;
    cout << "Please enter an integer value: " << endl;
    cin >> number;
    while (number > 0){
        if (number <= 0){
            break;
        }
        else if (number % 5 == 0){
            v.erase(v.begin() + 0);
        }
        else if (number % 3 ==0){
            v.pop_back();
        }
        else {
            v.push_back(number);
        }
    cout << "Please enter an integer value: " << endl;
    cin >> number;
    }
}