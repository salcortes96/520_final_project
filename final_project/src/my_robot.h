#ifndef __BLOCK_AGENT__H
#define __BLOCK_AGENT__H 

#include "enviro.h"
#include <string>
#include <math.h>


namespace
{

    using namespace enviro;
    // Creating a state machine for the robot to finds its way through the maze
    // The first random maze has been genereated in config.json file
    // Maze robot has three sensors mounted: in front, side right and side left 

    class MovingForward : public State, public AgentInterface
    {
    public:
        void entry(const Event &e) {
            track_velocity(0, 0);
        }
        void during()
        {
            // In this state, we will move at a constant 3 units/sec 
            track_velocity(3, 0);     

            // when the robot encouters a wall in the front at a distance 27
            // it should rotate by 1 rad/sec
            if (sensor_value(0) < 30)
            {
                //turn to the right
                track_velocity(0, 1.7);

            }
            // approaching a wall so turn to the opesate direction
                if (sensor_value(1) > 60){
                track_velocity(0, 20); 
                }
                
                // approaching a wall so turn to the opesate direction
                //if (sensor_value(2) > 60){
                //track_velocity(0, -20); 
                //}


            // track the location of where the robot has been   
            // watch("keyup", [&](Event &e) {
            //     auto k = e.value()["key"].get<std::string>();
            //     if ( k == "w" || k == "s" ) {
            //       v = 0;               
            //     } else if ( k == "a" ) {
            //       omega = 0;
            //     } else if ( k == "d" ) {
            //       omega = 0;
            //     }

            // have the robot not go to the locations it has been
            // for ( double x = -200; x <= 200; x += 50) {
            // for ( double y = 0; y <= 200; y += 50 ) {
            //     add_agent("Thing", x, y, 0, { {"fill", "blue"}});
            // }

            
        }
        void exit(const Event &e) {}
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;
    };


    // the below class was not used int this assignment as
    class Rotating : public State, public AgentInterface
    {
    public:
        void entry(const Event &e) { rate = rand() % 2 == 0 ? 2 : -2; }
        void during()
        {
            track_velocity(0, rate);
            if (sensor_value(0) > 140)
            {
                emit(Event(tick_name));
            }
        }
        void exit(const Event &e) {}
        double rate;
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;
    };

    class WandererController : public StateMachine, public AgentInterface
    {

    public:
        WandererController() : StateMachine()
        {

            set_initial(moving_forward);
            tick_name = "tick_" + std::to_string(rand() % 1000); // use an agent specific generated
                                                                 // event name in case there are
                                                                 // multiple instances of this class
            add_transition(tick_name, moving_forward, rotating);
            add_transition(tick_name, rotating, moving_forward);
            moving_forward.set_tick_name(tick_name);
            rotating.set_tick_name(tick_name);
        }


        MovingForward moving_forward;
        Rotating rotating;
        std::string tick_name;
    };

    class Wanderer : public Agent
    {

    public:
        Wanderer(json spec, World &world) : Agent(spec, world)
        {
            add_process(wc);
        }

        WandererController wc;
    };

    DECLARE_INTERFACE(Wanderer);

}

#endif