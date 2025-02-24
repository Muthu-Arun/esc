#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include "xdevapi.h"
#include <chrono>
#include<vector>
#include<string>
struct user{
    int id;
    char user_name[128], password[128], name[200];

};
struct sensor_value{
    float val;
    int device_id;
    
};
struct user_devices{
    int user_id;
    char Name[200];
    char Metadata[500];
    
    user_devices(int usr_id, const char* name, const char* metadata) : user_id{usr_id}{
        strcpy(Name,name);
        strcpy(Metadata,metadata);
    }
};

class db{
private:
    std::unique_ptr<mysqlx::Session> session;
    std::unique_ptr<mysqlx::Schema> schema;
    
public:
    void insert_new_user(std::unique_ptr<user> user_data);
    void insert_sensor_data(std::unique_ptr<sensor_value> sensor_data);
    void add_device(std::unique_ptr<user_devices> new_device);
    void init();
    void get_user_devices(std::unique_ptr<user> user,std::vector<user_devices>& devices);
    void get_sensor_data(int device_id);


};
