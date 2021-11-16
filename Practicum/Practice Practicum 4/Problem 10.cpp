#ifndef PROBABILITY_H
#define PROBABILITY_H

class Probability{
    public:
    Probability();
    Probability(string myEvents [], int myProb_values[]);

    void ReadFile(string fileName);
    string getMostLikelyEvent (float threshold);
    
    private:
    string events [50];
    float prob_values[50];
};

#endif

Probability :: Probability(){
    for (int i=0; i < 50; i++){
        events[i]="";
    }
    for (int i = 0; i < 50; i++ ){ 
        prob_values[i] = 0.0; 
    }
}

Probability :: Probability (string myEvents [50], int myProb_values[50]){
    for (int i = 0; i<50; i++){
        events[i]=myEvents[i];    
    }
    for (int i = 0; i < 50; i++){
        prob_values[i]=myProb_values[i];
    }
}

void Probability :: ReadFile (string fileName){
    string line;
    int i=0;
    ifstream file (fileName.c_str());
    if (file.is_open()){
        while (getline(file, line)){
            string weatherS[2];
            split (line, ',', weatherS, 2);
            string weather = weatherS[0];
            float perc = stof(weatherS[1]);
            prob_values[i]=perc; 
            events[i] = weather;
            i++;
        }
    }
}

string Probability :: getMostLikelyEvent(float threshold){
    string eventLikely = "";
    for (int i = 0; i < 50; i++){
        if (threshold < prob_values[i]){
            eventLikely=events[i];
            return eventLikely;
        }
    }
    return "";

}