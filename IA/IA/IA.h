#ifndef IA_H
#define IA_H

#include "mbed.h"
#include "../../config.h"
#include "../../odometrie/Odometrie.h"
#include "../../motorsController/Md22/Md22.h"
#include "../../consignController/ConsignController.h"
#include "../../commandManager/CommandManager.h"
#include "../../debug/DebugUDP.h"
#include "Telemetre.h"


struct Vector
{
    int x;
    int y;
};

union UnionCommand
{
    Vector vector;
    int dist;
};

enum TypeCommande {STRAIGHT_LINE, GOTO, WAIT_LINE};

struct CommandDescription
{
    TypeCommande type;
    UnionCommand unionCommand;
    
    CommandDescription(TypeCommande type, int x, int y) :
        type(type)
    {
        unionCommand.vector.x = x;
        unionCommand.vector.y = y;
    }
    
    CommandDescription(int d, bool p) :
        type(p?STRAIGHT_LINE:WAIT_LINE)
    {
        unionCommand.dist = d;
    }
    
    inline char* getString() 
    {
        switch(type)
        {
            case GOTO :
                return "Goto";
                break;
            case WAIT_LINE :
                return "Wait line";
                break;
            case STRAIGHT_LINE :
                return "Straight line";
                break;
        }
    }
};

class IA
{
    public :
         IA(CommandManager *p_commandManager);
         void initIAOnEstDansLaMerde();
         void onEstDansLaMerde();
         void initIACaVa();
         void addGoTo(int x, int y);
         void addStraightLine(int d, bool p=true);
         
         void stopWaitLine();
         void popCommand();
         void pushCommands();
         
    private:
        CommandManager* commandManager;
        Telemetre av1;
        Telemetre av2;
        Telemetre ar;
        int noTelemEnCours;
       
        bool violet;
        
        bool robotDroitDevant;
        bool robotDerriere;
        bool avance;
        std::list<CommandDescription> listeDestinations;
        
        void refreshAvance();
        
        int curseur;
        
        Timeout tt;
};

#endif
