class Robot {
public:
vector<pair<int,int>> dirs = {
    {1,0},{0,1},{-1,0},{0,-1}
};
int x = 0;
int y = 0;
int dir = 0;
int w = 0, h = 0;
int perimeter = 0;
bool moved = false;
    Robot(int width, int height) {
        w = width;
        h = height;
        perimeter = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        moved = true;
        num %= perimeter;  

        if(num == 0 && (x != 0 || y != 0)){
            num = perimeter;
        }
        for(int i = 0; i < num; i++){
            int nx = x + dirs[dir].first;
            int ny = y + dirs[dir].second;

            while(nx < 0 || nx >= w || ny < 0 || ny >= h){
                dir = (dir + 1) % 4;
                nx = x + dirs[dir].first;
                ny = y + dirs[dir].second;
            }

            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(x == 0 && y == 0 && moved){
            return "South";
        }
        if(dir == 0) return "East";
        else if(dir == 1) return "North";
        else if(dir == 2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */