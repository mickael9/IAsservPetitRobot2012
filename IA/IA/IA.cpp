#include "IA.h"

IA::IA(CommandManager* p_commandManager) :
    commandManager(p_commandManager),
    av1(p21, p17, 1),
    av2(p22, p18, 0),
    
    ar(p20, p19, 2),
    noTelemEnCours(0),
    robotDroitDevant(false),
    robotDerriere(false),
    avance(true),
    curseur(0)
{
    pc.printf("Debut constructeur IA\n");
    
     //pin 8: envoie 1
    DigitalOut pin8(p8);
    pin8=1;
    
    wait(1);
    
     //pin 6: couleur (1=violet, 0=rouge)
    DigitalIn pin6(p6);
    pin6.mode(PullDown);
    if(pin6)
        this->violet=true;
    else
        this->violet=false;
        
   pc.printf("%s\n", violet?"violet":"rouge");
       
        
        
   pc.printf("Fin constructeur IA\n");
}

void IA::initIAOnEstDansLaMerde()
{
    //pin 7: tirette ( 0 => go!)
    DigitalIn tirette(p7);
    tirette.mode(PullDown);
    
    pc.printf("Attente tirette pour calage bordure\n");
    while(!tirette)
    {
        wait_ms(20);
    }
    wait(1);
    
    pc.printf("Tirette retiree, debut calage bordure\n");
    commandManager->calageBordurePetit(violet?0:1);
    
    pc.printf("Fin calage bordure\n");
    pc.printf("Attente remise tirette\n");
    
    while(tirette)
    {
        wait_ms(20);
    }
    wait(1);
    
    pc.printf("Retirer tirette pour demarrer IA\n");
    while(!tirette)
    {
        wait_ms(20);
    }
    
    //vers la premiere bouteille
    
    addGoTo(570, 250);
    addGoTo(570, 2900);
    
    /*
    addStraightLine(50, false);
    addStraightLine(-100);
    
    //vers la deuxi&#65533;me
    addGoTo(1813,1700);
    //addTurn(90);
    
    /*addStraightLine(50, false);
    addStraightLine(-100);*/
}

void IA::onEstDansLaMerde()
{
    // Lancement des mesures par les t&#65533;l&#65533;m&#65533;tres
    /*
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   Meas
    {
        switch(noTelemEnCours)
        {
            case 0 :
                ar.update();
            break;
            case 1 :
                av1.update();
            break;
            case 2 :
                av2.update();
                break;
        }
        noTelemEnCours = (noTelemEnCours+1)%3;
    }*/
    
    
    //ar.computeMoyenne();
    
    //pc.printf("Le robot %s.\n", avance?" avance":" recule");
    
    if(avance)
    {
        av1.computeMoyenne();
        av2.computeMoyenne();
        
        pc.printf("%f ; %f\n", av1.getMoyenne(), av2.getMoyenne());
            
            
        //pc.printf("%f ; %f\n", av1.getMoyenne(), av2.getMoyenne());
        if(!robotDroitDevant)
        {
            //pc.printf("Pas de Robot Devant : %f ; %f ; %f\n", av1.getMoyenne(), av2.getMoyenne(), ar.getMoyenne());
            
         
            if(av1.getMoyenne() < 0.025 || av2.getMoyenne() < 0.25)
            {
                pc.printf("Emergency Stop !!!\n");
                robotDroitDevant = true;
                commandManager->setEmergencyStop();
            }
        }
        else
        {
            //pc.printf("Robot Devant\n");
            if(av1.getMoyenne() > 0.030 && av2.getMoyenne() > 0.28) // Comparateur &#65533; hyst&#65533;r&#65533;sis : seuil sup&#65533;rieur &#65533; celui qui active l&#65533;arret
            {
                robotDroitDevant = false;
                
                commandManager->resetEmergencyStop();
                pushCommands();
                refreshAvance();
                
                pc.printf("Plus de Robot Devant\n");
            }
        }
    }
    else
    {
        ar.computeMoyenne();
        if(!robotDerriere)
        {
            if(ar.getMoyenne() < 0.035)
            {
                commandManager->setEmergencyStop();
                robotDerriere = true;
            }
        }
        else
        {
            pc.printf("Robot Derriere\n");
            if(ar.getMoyenne() > 0.04) // Comparateur &#65533; hyst&#65533;r&#65533;sis : seuil sup&#65533;rieur &#65533; celui qui active l&#65533;arret
            {
                commandManager->resetEmergencyStop();
                pushCommands();
                refreshAvance();
                robotDerriere = false;
            }
        }
    }
}

void IA::pushCommands()
{
    curseur = 0;
    
    int j = 0;
    for(std::list<CommandDescription>::iterator i=listeDestinations.begin(); i!=listeDestinations.end(); ++i)
    {
    ++j;
        if(i->type == STRAIGHT_LINE)
        {
             commandManager->addStraightLine(i->unionCommand.dist);
        }
        else if(i->type == GOTO)
        {
            
              commandManager->addGoTo(i->unionCommand.vector.x, i->unionCommand.vector.y);
        }
        else if(i->type == WAIT_LINE)
        {
            commandManager->addStraightLine(i->unionCommand.dist);
            tt.attach(this, &IA::popCommand, 1.);
        }
    }
    pc.printf("Nbr de commandes restantes : %d\n", j);
}

void IA::initIACaVa()
{
    
}   

void IA::addGoTo(int x, int y)
{
pc.printf("goto %d %d\n", x,y);

   if(violet)
        listeDestinations.push_back(CommandDescription(GOTO, x,y));
   else
        listeDestinations.push_back(CommandDescription(GOTO, x,-y));
        
        
        pc.printf("goto %d %d\n", listeDestinations.back().unionCommand.vector.x, listeDestinations.back().unionCommand.vector.y);
        
   commandManager->addGoTo(listeDestinations.back().unionCommand.vector.x, listeDestinations.back().unionCommand.vector.y);
}

void IA::addStraightLine(int d, bool p)
{
    listeDestinations.push_back(CommandDescription(d, p));
    
    commandManager->addStraightLine(d);
}

void IA::stopWaitLine()
{
    pc.printf("bientot...\n");
    commandManager->setEmergencyStop();
    popCommand();
    commandManager->resetEmergencyStop();
    pushCommands();
    pc.printf("Il s est arrete\n");
}

void IA::popCommand()
{
    
        pc.printf("Done : %s (%d).\n", listeDestinations.front().getString(), curseur);
    
            listeDestinations.pop_front();
    
             refreshAvance();
             
            if(listeDestinations.front().type == WAIT_LINE)
            {
                pc.printf("Il va bientot arreter !\n");
                 tt.attach(this, &IA::stopWaitLine, 0.1);
            }
}

void IA::refreshAvance()
{
    //avance = !listeDestinations.front().type || listeDestinations.front().unionCommand.dist < 0;
}
