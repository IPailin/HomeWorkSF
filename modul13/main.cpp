#include <iostream>
#include <memory>
#include <vector>
#include <stdio.h>

const int ROUTE = 10;

void test(struct city *arr_city);
void find_citys(struct city *arr, struct city *root, int *result, int *counter, int *finish);
bool check(int *result, int number);
void step(int *result, struct city *arr, int *counter);


struct city{

    std::string name;
    int number_unique {0};
    struct city *route[ROUTE] = {nullptr};
    int counter_route {0};
};


int main() {

    struct city arr_city[20];
    bool marker[20] = {false};

    int result[20];
    for(int i = 0; i < 20; ++i){
        result[i] = -1;
    }

    test(arr_city);

    std::string s = arr_city[0].name;
    s = arr_city[1].name;
    s = arr_city[1].route[0]->name;

    int number {6};
    int counter {0};
    int finish {0};
    marker[number] = true;
    find_citys(arr_city,&arr_city[number],result, &counter, &finish);

    for(int i = 0; i < 20; ++i){
        if(arr_city[i].name == ""){
            break;
        }

        if(result[i] != -1){
            std::cout << arr_city[i].name << std::endl;
        }
    }


    return 0;
}
bool check(int *result, int number){

    for(int i = 0; i < 20; i++){
        if(result[i] == number){
            return false;
        }
    }

    return true;

}

void step(int *result, struct city *arr, int *counter){
    struct city root;
    int index {0};

    for(int i = 0; i < 20; ++i){
        if(result[i] == -1){
            break;
        }
        else{
            
            index = result[i];
            for(int i = 0; i < ROUTE; ++i){



                if(arr[index].route[i] == nullptr){
                    break;
                }
        
                if(check(result, arr[index].route[i]->number_unique)){
                    result[*counter] = arr[index].route[i]->number_unique;
                    (*counter)++;
                }
            }

        }
    }
}

void find_citys(struct city *arr, struct city *root, int *result, int *counter, int *finish){

    for(int i = 0; i < ROUTE; ++i){



        if(root->route[i] == nullptr){
            break;
        }
        //marker[root->route[i]->number_unique] = true;
        if(check(result, root->route[i]->number_unique)){
            result[*counter] = root->route[i]->number_unique;
            (*counter)++;
        }
        
        //find_citys(arr,marker,root->route[i], count);


    }

    (*finish)++;

    step(result, arr, counter);
    (*finish)++;

    step(result, arr, counter);
    (*finish)++;
    




}

void test(struct city *arr_city){

    struct city kras;
    struct city novosib;

    int counter_city {0};

    kras.name = "krasnoyarsk";
    kras.number_unique = counter_city++;
    kras.route[kras.counter_route++] = &novosib;
    //arr_city[counter_city++] = kras;

    novosib.name = "novosib";
    novosib.number_unique = counter_city++;
    novosib.route[novosib.counter_route++] = &kras;
    //arr_city[counter_city++] = novosib;

    struct city barnaul;
    barnaul.name = "barnaul";
    barnaul.number_unique = counter_city++;
    barnaul.route[barnaul.counter_route++] = &novosib;

    novosib.route[novosib.counter_route++] = &barnaul;
    //arr_city[counter_city++] = barnaul;

    struct city abakan;
    abakan.name = "abakan";
    abakan.number_unique = counter_city++;
    abakan.route[abakan.counter_route++] = &barnaul;

    barnaul.route[barnaul.counter_route++] = &abakan;
    //arr_city[counter_city++] = abakan;

    struct city ekat;
    ekat.name = "ekaterenburg";
    ekat.number_unique = counter_city++;
    ekat.route[ekat.counter_route++] = &kras;

    kras.route[kras.counter_route++] = &ekat;
    //arr_city[counter_city++] = ekat;
    

    struct city chel;
    chel.name = "chelyabinsk";
    chel.number_unique = counter_city++;
    chel.route[chel.counter_route++] = &ekat;

    ekat.route[ekat.counter_route++] = &chel;

    struct city kansk;
    kansk.name = "kansk";
    kansk.number_unique = counter_city++;
    kansk.route[kansk.counter_route++] = &kras;

    kras.route[kras.counter_route++] = &kansk;


    kansk.route[kansk.counter_route++] = &abakan;
    abakan.route[abakan.counter_route++] = &kansk;

    struct city moskov;
    moskov.name = "moskov";
    moskov.number_unique = counter_city;
    moskov.route[moskov.counter_route++] = &novosib;

    novosib.route[novosib.counter_route++] = &moskov;

    struct city piter;
    piter.name = "piter";
    piter.number_unique = counter_city;
    piter.route[piter.counter_route++] = &moskov;

    struct city berlin;
    berlin.name = "berlin";
    berlin.number_unique = counter_city;
    berlin.route[berlin.counter_route++] = &moskov;

    moskov.route[moskov.counter_route++] = &piter;
    moskov.route[moskov.counter_route++] = &berlin;

    arr_city[8] = piter;
    arr_city[9] = berlin;
    arr_city[7] = moskov;
    arr_city[1] = novosib;
    arr_city[2] = barnaul;
    arr_city[3] = abakan;
    arr_city[0] = kras;
    arr_city[6] = kansk;
    arr_city[4] = ekat;
    arr_city[5] = chel;

    std::string s = novosib.route[0]->name;

}