#ifndef TEXTBOOK_H
#define TEXTBOOK_H

class Textbook{
    public:
    Textbook();
    Textbook(string t, int p, float c, bool o);
    
    string getTitle ();
    void setTitle (string t);
    void setPages (int p);
    int getPages ();
    void setCost (float c);
    float getCost ();
    void setOnline (bool o);
    bool getOnline ();
    
    float costPerPage();
    
    private:
    string title;
    int pages;
    float cost;
    bool online;
};

#endif 