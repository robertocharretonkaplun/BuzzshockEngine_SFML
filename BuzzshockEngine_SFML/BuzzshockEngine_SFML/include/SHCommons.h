#pragma once

enum PartyMembership
{
  LIBERAL = 0,
  FASCIST = 1,
  HITLER = 2,
};

static int numLiberal = 6;
static int numFascist = 11;

static int numFascistPolicy = 11;
static int numLiberalPolicy = 6;


// Liberal win
static int totalLiberalPolicy = 5;
static bool isHitlerKilled = true; // Plus 3 Fascist policy

// Fascist win
static int totalFascistPolicy = 6;
static bool isHitlerChancellor = true;