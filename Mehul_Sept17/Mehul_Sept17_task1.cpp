#include<iostream>
#include<limits.h>
#include<algorithm>
#include<cstdint>

class Pedestrian{
    private:
    uint32_t pedestrian_id;
    float distance_from_vehicle;

    public:
    Pedestrian(uint pedestrianid = 0, float distance = 0.0f): pedestrian_id(pedestrianid),distance_from_vehicle(distance){}

    void updateDistance(float newDistance){
        distance_from_vehicle = newDistance;
        std::cout<<distance_from_vehicle;
    }

    float getDistance() const{
        return distance_from_vehicle;
    }

    uint32_t getId() const {
        return pedestrian_id;
    }

};

void printPedestrianInfo(const Pedestrian& ped) {
    std::cout << "Pedestrian ID: " << ped.getId()
         << ", Distance: " << ped.getDistance() << " meters" << std::endl;
}


void printClosestPedestrian(const Pedestrian* closest) {
    if (closest != nullptr) {
        std::cout << "\nClosest pedestrian detected:" << std::endl;
        printPedestrianInfo(*closest);
    } else {
        std::cout << "\nNo pedestrian detected." << std::endl;
    }
}

void findClosestPedestrian(Pedestrian* array, uint size,const Pedestrian*& closest ){
    if(array == nullptr|| size==0){
        closest=nullptr;
        return;
    }

    closest  =&array[0];
    for(uint32_t i=1;i<size;i++){
        if(array[i].getDistance() < closest->getDistance()){
            closest=&array[i];
        }
    }



}


int main(){

    Pedestrian* pedestrians = new Pedestrian[3]{
        Pedestrian(101,12.4f),Pedestrian(102,8.7f),Pedestrian(103,15.1f)
    };

    std::cout<<"All Pedestrians: "<<std::endl;
        for(int i=0;i<3;i++){
        printPedestrianInfo(pedestrians[i]);
    }

    const Pedestrian* closest = nullptr;
    findClosestPedestrian(pedestrians,3, closest);
    printClosestPedestrian(closest);

    return 0;
}