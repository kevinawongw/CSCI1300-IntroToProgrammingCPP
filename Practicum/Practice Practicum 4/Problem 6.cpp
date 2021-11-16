#ifndef INVESTMENTPROFILE_H
#define INVESTMENTPROFILE_H

class InvestmentProfile{
    public:
    InvestmentProfile();
    InvestmentProfile (string myCompanyName, float mySharesHeld);    
    
    string getCompanyName();
    void setCompanyName(string myCompanyName);
    float getSharesHeld ();
    void setSharesHeld (float mySharesHeld);
    
    string influence ();
    
    private:
    string companyName = "Company co.";
    float sharesHeld = 100.0;
};
#endif


InvestmentProfile :: InvestmentProfile (){
    string companyName = "Company co.";
    float sharesHeld = 100.0;
}

InvestmentProfile :: InvestmentProfile (string myCompanyName, float mySharesHeld){
    companyName = myCompanyName;
    sharesHeld = mySharesHeld;
}

string InvestmentProfile :: getCompanyName(){
    return companyName;
}

void InvestmentProfile :: setCompanyName(string myCompanyName){
    companyName = myCompanyName;
}

float InvestmentProfile :: getSharesHeld (){
    return sharesHeld;
}

void InvestmentProfile :: setSharesHeld (float mySharesHeld){
    sharesHeld = mySharesHeld;
}

string InvestmentProfile :: influence (){
    if (sharesHeld < 50.0){
        return "Minority Shareholder";
    }
    else if (sharesHeld >= 50.0 && sharesHeld < 100.0){
        return "Majority Shareholder";
    }
    else{
        return "Sole Shareholder";
    }
}