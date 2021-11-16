int CountLower(string a){
    int lower = 0;
    if (a.length() == 0)
    {
        return -1;
    }
    else 
    {
        for (int i =0; i< a.length(); i++){
            if (islower(a[i]))
            {
                lower++;
            }
        }
    }
    if (lower == 0){
        return -2;
    }
    else{
        return lower;
    }    
}