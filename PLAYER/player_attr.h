#ifndef PLAYER_ATTR_H
#define PLAYER_ATTR_H

#include <stdbool.h> 

enum PLAYERTYPE {
    MAGE,
    MELEE,
    RANGER,
    SUMMONER,
    IMMUNE,
    ARM
};

struct player {
    // universal stats
    enum PLAYERTYPE damageClass;

    int health;
    int groundSpeed;
    int acceleration;
    int jumpHeight;
    int damage;
    bool isDebuffed;
    bool isBuffed;

    // class specific stats
    union {
        struct {
            bool isDamageLasting;
            bool isFlying;
            int lastingDamageTime;
            int flightTime;
            int flightReloadTime;
        } mage;
        
        struct {
            bool hasStunned;
            bool isEnraged;
            int stunReloadTime;
            int enragedTime;
            int enragedReloadTime;
        } melee;

        struct {
            bool bigShotUsed;
            bool isStealth;
            int bigShotReloadTime;
            int stealthTime;
            int stealthReloadTime;
        } ranger;

        struct {
            bool littleMinionUsed;
            bool bigMinionUsed;
            int littleMinionReloadTime;
            int bigMinionReloadTime;
        } summoner;

        struct {
            bool isVampire; 
            int vampireTime;
            int vampireReloadTime;
        } immune;

        struct {
            bool hasBlades;
            bool hasGrenade;
            int bladeReloadTime;
            int grenadeReloadTime; 
            int bladeNumber;
        } arm;
    } specs;
};

#endif