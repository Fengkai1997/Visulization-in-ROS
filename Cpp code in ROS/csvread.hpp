



//void csvreadx(c);

void csvreadx(int c,std:: vector<float> &data_line_x,std::string &path_read1){
    std::ifstream inputFile(path_read1); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <c+1;j++){ 
            getline(readstr,number,','); 
            data_line_x.push_back(atof(number.c_str())); 
            }
    }
}

void csvready(int c,std::vector<float>& data_line_y){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat1379243/Boat00_1379243_lati.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <c+1;j++){ 
            getline(readstr,number,','); 
            data_line_y.push_back(atof(number.c_str())); 
            }
    }
}

void csvreadcog(int c,std:: vector<float>& data_line_cog){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat1379243/Boat00_1379243_COG.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <c+1;j++){ 
            getline(readstr,number,','); 
            data_line_cog.push_back(atof(number.c_str())); 
            }
    }
}


void csvreadupdate(int c,std::vector<float> &data_line_update){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat1379243/Boat00_1379243_timeinterval.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <c+1;j++){ 
            getline(readstr,number,','); 
            data_line_update.push_back(atof(number.c_str())); 
            }
    }
}

void csvreadtime(int c, std::vector<std::string> &data_line_time){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat1379243/Boat00_1379243_time.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <c+1;j++){ 
            getline(readstr,number,','); 
            data_line_time.push_back(number.c_str()); 
            }
    }
}
