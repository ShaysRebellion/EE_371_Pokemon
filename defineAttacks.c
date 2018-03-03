#include "game_structs.h"
#include <string.h>
#include <stdio.h>

//this function defines all of the attacks that will be in the game
//as we develop the game further we can add more attacks and play with
//the values. Follow this format to add an attack, and update NUMATTACKS
//in game_structs.h as we add more attacks.
attack* defineAttacks(){
	static attack allAttacks[NUMATTACKS];
	
	//***********************************************************
	//Attacks for Bulbasaur

	attack tackle;
	strcpy(tackle.name, "Tackle");
	tackle.damage = 40;
	tackle.PP = 35;
	tackle.numValue = 0;
	allAttacks[tackle.numValue] = tackle;

	attack vineWhip;
	strcpy(vineWhip.name, "Vine Whip");
	vineWhip.damage = 45;
	vineWhip.PP = 25;
	vineWhip.numValue = 1;
	allAttacks[vineWhip.numValue] = vineWhip;

	attack razorLeaf;
	strcpy(razorLeaf.name, "Razor Leaf");
	razorLeaf.damage = 55;
	razorLeaf.PP = 25;
	razorLeaf.numValue = 2;
	allAttacks[razorLeaf.numValue] = razorLeaf;

	attack doubleEdge;
	strcpy(doubleEdge.name, "Double-Edge");
	doubleEdge.damage = 120;
	doubleEdge.PP = 15;
	doubleEdge.numValue = 3;
	allAttacks[doubleEdge.numValue] = doubleEdge;
	
	//***********************************************************
	//Attacks for Charmander
	
	attack scratch;
	strcpy(scratch.name, "SCRATCH");
	scratch.damage = 5;
	scratch.PP = 10;
	scratch.numValue = 4;
	allAttacks[scratch.numValue] = scratch;

	attack fireFang;
	strcpy(fireFang.name, "Fire Fang");
	fireFang.damage = 65;
	fireFang.PP = 15;
	fireFang.numValue = 5;
	allAttacks[fireFang.numValue] = fireFang;

	attack flameBurst;
	strcpy(flameBurst.name, "Flame Burst");
	flameBurst.damage = 70;
	flameBurst.PP = 15;
	flameBurst.numValue = 6;
	allAttacks[flameBurst.numValue] = flameBurst;

	attack fireSpin;
	strcpy(fireSpin.name, "Fire Spin");
	fireSpin.damage = 35;
	fireSpin.PP = 15;
	fireSpin.numValue = 7;
	allAttacks[fireSpin.numValue] = fireSpin;

	
	//***********************************************************
	//Attacks for Squirtle

	attack waterGun;
	strcpy(waterGun.name, "Water Gun");
	waterGun.damage = 40;
	waterGun.PP = 25;
	waterGun.numValue = 8;
	allAttacks[waterGun.numValue] = waterGun;

	attack bubble;
	strcpy(bubble.name, "Bubble");
	bubble.damage = 40;
	bubble.PP = 30;
	bubble.numValue = 9;
	allAttacks[bubble.numValue] = bubble;

	attack bite;
	strcpy(bite.name, "Bite");
	bite.damage = 60;
	bite.PP = 25;
	bite.numValue = 10;
	allAttacks[bite.numValue] = bite;

	attack rapidSpin;
	strcpy(rapidSpin.name, "Rapid Spin");
	rapidSpin.damage = 60;
	rapidSpin.PP = 25;
	rapidSpin.numValue = 11;
	allAttacks[rapidSpin.numValue] = rapidSpin;

	//***********************************************************
	//Attacks for Pikachu

	attack thunderShock;
	strcpy(thunderShock.name, "Thunder Attack");
	thunderShock.damage = 40;
	thunderShock.PP = 30;
	thunderShock.numValue = 12;
	allAttacks[thunderShock.numValue] = thunderShock;

	attack thunderBolt;
	strcpy(thunderBolt.name, "Thunder Bolt");
	thunderBolt.damage = 90;
	thunderBolt.PP = 15;
	thunderBolt.numValue = 13;
	allAttacks[thunderBolt.numValue] = thunderBolt;

	attack spark;
	strcpy(spark.name, "Spark");
	spark.damage = 65;
	spark.PP = 20;
	spark.numValue = 14;
	allAttacks[spark.numValue] = spark;

	attack nuzzle;
	strcpy(nuzzle.name, "Nuzzle");
	nuzzle.damage = 20;
	nuzzle.PP = 20;
	nuzzle.numValue = 15;
	allAttacks[nuzzle.numValue] = nuzzle;

	//***********************************************************
	//Attacks for Eevee

	attack covet;
	strcpy(covet.name, "Covet");
	covet.damage = 60;
	covet.PP = 25;
	covet.numValue = 16;
	allAttacks[covet.numValue] = covet;

	attack lastResort;
	strcpy(lastResort.name, "Last Resort");
	lastResort.damage = 140;
	lastResort.PP = 5;
	lastResort.numValue = 17;
	allAttacks[lastResort.numValue] = lastResort;

	attack facade;
	strcpy(facade.name, "Facade");
	facade.damage = 70;
	facade.PP = 20;
	facade.numValue = 18;
	allAttacks[facade.numValue] = facade;

	attack shadowBall;
	strcpy(shadowBall.name, "Shadow Ball");
	shadowBall.damage = 80;
	shadowBall.PP = 15;
	shadowBall.numValue = 19;
	allAttacks[shadowBall.numValue] = shadowBall;

	//***********************************************************
	//Attacks for Chikorita
	
	attack hiddenPower;
	strcpy(hiddenPower.name, "Hidden Power");
	hiddenPower.damage = 60;
	hiddenPower.PP = 15;
	hiddenPower.numValue = 20;
	allAttacks[hiddenPower.numValue] = hiddenPower;
	
	attack magicalLeaf;
	strcpy(magicalLeaf.name, "Magical Leaf");
	magicalLeaf.damage = 60;
	magicalLeaf.PP = 20;
	magicalLeaf.numValue = 21;
	allAttacks[magicalLeaf.numValue] = magicalLeaf;
	
	
	attack bodySlam;
	strcpy(bodySlam.name, "Body Slam");
	bodySlam.damage = 85;
	bodySlam.PP = 15;
	bodySlam.numValue = 22;
	allAttacks[bodySlam.numValue] = bodySlam;
	
	
	attack solarBeam;
	strcpy(solarBeam.name, "Solar Beam");
	solarBeam.damage = 120;
	solarBeam.PP = 10;
	solarBeam.numValue = 23;
	allAttacks[solarBeam.numValue] = solarBeam;
	
	//***********************************************************
	//Attacks for Cyndaquil
	
	attack flameWheel;
	strcpy(flameWheel.name, "Flame Wheel");
	flameWheel.damage = 60;
	flameWheel.PP = 25;
	flameWheel.numValue = 24;
	allAttacks[flameWheel.numValue] = flameWheel;
	
	attack flamethrower;
	strcpy(flamethrower.name, "Flamethrower");
	flamethrower.damage = 90;
	flamethrower.PP = 15;
	flamethrower.numValue = 25;
	allAttacks[flamethrower.numValue] = flamethrower;
	
	attack inferno;
	strcpy(inferno.name, "Inferno");
	inferno.damage = 100;
	inferno.PP = 5;
	inferno.numValue = 26;
	allAttacks[inferno.numValue] = inferno;
	
	attack eruption;
	strcpy(eruption.name, "Eruption");
	eruption.damage = 150;
	eruption.PP = 5;
	eruption.numValue = 27;
	allAttacks[eruption.numValue] = eruption;

	//***********************************************************
	//Attacks for Totodile
	
	attack rage;
	strcpy(rage.name, "Rage");
	rage.damage = 20;
	rage.PP = 20;
	rage.numValue = 28;
	allAttacks[rage.numValue] = rage;
	
	attack chipAway;
	strcpy(chipAway.name, "Chip Away");
	chipAway.damage = 70;
	chipAway.PP = 20;
	chipAway.numValue = 29;
	allAttacks[chipAway.numValue] = chipAway;
	
	attack slash;
	strcpy(slash.name, "Slash");
	slash.damage = 70;
	slash.PP = 20;
	slash.numValue = 30;
	allAttacks[slash.numValue] = slash;
	
	attack hydroPump;
	strcpy(hydroPump.name, "Hydro Pump");
	hydroPump.damage = 110;
	hydroPump.PP = 5;
	hydroPump.numValue = 31;
	allAttacks[hydroPump.numValue] = hydroPump;

	return allAttacks;
}