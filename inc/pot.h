#ifndef POT_H
#define POT_H

class POT{
    private:
        String state;
        int CCW;
        int MID;
        int CW;
    public:
        void set_CCW();
        void set_MID();
        void set_CW();
        int get_CCW();       //to be called in main
        int get_MID();       //to be called in main 
        int get_CW();        //to be called in main
        String get_state();  //to be called in main
};

#endif
