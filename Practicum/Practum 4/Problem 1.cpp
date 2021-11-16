#ifndef RACETRACK_H
#define RACETRACK_H

class RaceTrack{
    public:
    RaceTrack ();
    RaceTrack (string raceName);
    
    bool addCar (float topSpeed, string carModel);
    float calcAvgSpeed();
    int countAvailable(float minSpeed);
    int countAvailableModels(string model);
    
    private:
    string name;
    void initDataMembers();
};

#endif 