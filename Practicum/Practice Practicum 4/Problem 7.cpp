#ifndef MOVIEREVIEW_H
#define MOVIEREVIEW_H

class MovieReview{
    public:
    MovieReview();
    MovieReview (string myName, string myGenre, int myRating);    
    
    string getName();
    void setName(string myName);
    string getGenre();
    void setGenre (string myGenre);
    int getRating ();
    void setRating (int myRating);
    
    string howYouReallyFeel ();
    
    private:
    string name = "Goofy Movie 2: The Extremely Goofy Movie";
    string genre = "Thriller";
    int rating = 10;
};
#endif


MovieReview :: MovieReview (){
    string name = "Goofy Movie 2: The Extremely Goofy Movie";
    string genre = "Thriller";
    int rating = 10;
}

MovieReview :: MovieReview (string myName, string myGenre, int myRating){
    name = myName;
    genre = myGenre;
    rating = myRating;
}

string MovieReview :: getName(){
    return name;
}

void MovieReview :: setName(string myName){
    name = myName;
}

string MovieReview :: getGenre (){
    return genre;
}

void MovieReview :: setGenre (string myGenre){
    genre = myGenre;
}

int MovieReview :: getRating(){
    return rating;
}

void MovieReview :: setRating(int myRating){
    rating = myRating;
}

string MovieReview :: howYouReallyFeel (){
    if (rating < 0){
        return "Garbage";
    }
    else if (rating > 0 && rating <= 5){
        return "Boo";
    }
    else if (rating >5 && rating <=7){
        return "Meh";
    }
    else if (rating > 7 && rating <= 9){
        return "Good";
    }
    else {
        return "Must be THE Goofy Movie 2";
    }
}