#include "CisternMap.h"

#include "Item.h"
#include "CommonUtilities/Globals.h"


void CisternMap::Init()
{
#pragma region ITEMS
	// bothbeds
	Item rungKeys(ItemChar::RungKeys, "rung keys", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 's', false);
	Item map(ItemChar::Map, "cistern map", float2{ 10, 10 }, float2{ 10, 10 }, ItemChar::Count, 'a', false);

	// kitchen
	Item cupWithoutLid(ItemChar::CupWithoutLid, "cup without lid", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'a', false);
	Item potatoKnacke(ItemChar::PotatoKnacke, "potato crispbread", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 's', false);
		potatoKnacke.SetAmount(3);
	Item coffee(ItemChar::Coffee, "coffee", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'd', false);

	// g0_clock
	Item portableClock(ItemChar::PortableClock, "clock", float2{ 10,10 }, float2{ 10,50 }, ItemChar::Count, 'd', false);
	Item schedule(ItemChar::Schedule, "schedule", float2{ 10,10 }, float2{ 10,50 }, ItemChar::Count, 'a', false);

	// mid_ag
	Item stone(ItemChar::Stone, "perfectly ordinary stone", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'e', false);

	// wardrobe
	Item cleanAndDryOverall(ItemChar::OverallCleanAndDry, "clean and dry overall", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'e', false);
		cleanAndDryOverall.SetAmount(2);
	//Item dirtyAndWetOverall(ItemChar::OverallDirtyAndWet, "dirty and wet overall", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'w', false);
		//dirtyAndWetOverall.SetAmount(3);
	Item cleanButWetOverall(ItemChar::OverallCleanButWet, "clean but wet overall", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'q', false);
		cleanButWetOverall.SetAmount(1);
	Item dryButDirtyOverall(ItemChar::OverallDryButDirty, "dry but dirty overall", float2{ 10,10 }, float2{ 10,10 }, ItemChar::Count, 'a', false);
		dryButDirtyOverall.SetAmount(2);
#pragma endregion

// Locations
#pragma region GO
	myG0_inTopBed.path = "myG0_inTopBed";
	myG0_inTopBed.l = &myG0_clock;
	myG0_inTopBed.isPartOfRotatedLocation = true;

	myG0_bothBeds.path = "myG0_bothBeds";
	myG0_bothBeds.f = &myG0_inTopBed;
	myG0_bothBeds.b = &myG0_clock;
	myG0_bothBeds.l = &myG0_wardrobe;
	myG0_bothBeds.r = &myG0_kitchen_and_wayOut;
	myG0_bothBeds.isPartOfRotatedLocation = true;
	myG0_bothBeds.items.push_back(rungKeys);
	myG0_bothBeds.items.push_back(map);

	myG0_kitchen_and_wayOut.path = "myG0_kitchen_and_wayOut";
	myG0_kitchen_and_wayOut.f = &myG0_ladderToG0;
	myG0_kitchen_and_wayOut.b = &myG0_wardrobe;
	myG0_kitchen_and_wayOut.l = &myG0_bothBeds;
	myG0_kitchen_and_wayOut.r = &myG0_desk;
	myG0_kitchen_and_wayOut.isPartOfRotatedLocation = true;
	myG0_kitchen_and_wayOut.items.push_back(cupWithoutLid);
	myG0_kitchen_and_wayOut.items.push_back(coffee);
	myG0_kitchen_and_wayOut.items.push_back(potatoKnacke);

	myG0_desk.path = "myG0_desk";
	myG0_desk.f = &myG0_desk_diary;
	myG0_desk.b = &myG0_toilet;
	myG0_desk.l = &myG0_kitchen_and_wayOut;
	myG0_desk.r = &myG0_clock;
	myG0_desk.isPartOfRotatedLocation = true;

	myG0_desk_diary.path = "myG0_desk_diary";
	myG0_desk_diary.b = &myG0_desk;
	myG0_desk_diary.isPartOfRotatedLocation = true;
	myG0_desk_diary.isDeskDiaryLocation = true;

	myG0_toilet.path = "myG0_toilet";
	myG0_toilet.b = &myG0_desk;
	myG0_toilet.l = &myG0_clock;
	myG0_toilet.r = &myG0_wardrobe;
	myG0_toilet.isPartOfRotatedLocation = true;

	myG0_wardrobe.path = "myG0_wardrobe";
	myG0_wardrobe.b = &myG0_kitchen_and_wayOut;
	myG0_wardrobe.l = &myG0_toilet;
	myG0_wardrobe.r = &myG0_bothBeds;
	myG0_wardrobe.isPartOfRotatedLocation = true;
	myG0_wardrobe.items.push_back(cleanAndDryOverall);
	//myG0_wardrobe.items.push_back(dirtyAndWetOverall);
	myG0_wardrobe.items.push_back(cleanButWetOverall);
	myG0_wardrobe.items.push_back(dryButDirtyOverall);

	myG0_clock.path = "myG0_clock";
	myG0_clock.b = &myG0_bothBeds;
	myG0_clock.l = &myG0_desk;
	myG0_clock.r = &myG0_toilet;
	myG0_clock.isPartOfRotatedLocation = true;
	myG0_clock.isClockLocation = true;
	myG0_clock.items.push_back(portableClock);
	myG0_clock.items.push_back(schedule);

	myG0_ladderToG0.path = "myG0_ladderToG0";
	myG0_ladderToG0.f = &myG0_bothBeds;
	myG0_ladderToG0.b = &myG0_corridorToCistern;
	myG0_ladderToG0.lvl = -1; // LEVEL -1

	myG0_ladderToCistern.path = "myG0_ladderToCistern";
	myG0_ladderToCistern.f = &myG0_wayIn;
	myG0_ladderToCistern.b = &myG0_corridorToG0;
	myG0_ladderToCistern.lvl = -1; // LEVEL -1

	myG0_corridorToG0.path = "myG0_corridorToG0";
	myG0_corridorToG0.f = &myG0_ladderToG0;
	myG0_corridorToG0.b = &myG0_ladderToCistern;
	myG0_corridorToG0.lvl = -1; // LEVEL -1

	myG0_corridorToCistern.path = "myG0_corridorToCistern";
	myG0_corridorToCistern.f = &myG0_ladderToCistern;
	myG0_corridorToCistern.b = &myG0_ladderToG0;
	myG0_corridorToCistern.lvl = -1; // LEVEL -1

	myG0_wayIn.path = "myG0_wayIn";
	myG0_wayIn.f = &myG0_ladderToCistern;
	myG0_wayIn.b = &myMid_AG;
	myG0_wayIn.l = &myH0_sewer;
	myG0_wayIn.r = &my0S_f;

	myG0_sewer.path = "myG0_sewer";
	myG0_sewer.l = &my0S_g;
	myG0_sewer.r = &myH0_wayIn;
#pragma endregion

#pragma region VENTS_INSIDES
	my0E_r_Inside.path = "my0E_r_Inside";
	my0E_r_Inside.b = &my0E_r;
	my0E_r_Inside.isOpen = false;
	my0E_r_Inside.NPCs.emplace_back(&myOverallNPC);
	////.f = &;

	my0E_q_Inside.path = "my0E_q_Inside";
	my0E_q_Inside.b = &my0E_q;
	my0E_q_Inside.isOpen = false;
	////.f = &;

	my0E_p_Inside.path = "my0E_p_Inside";
	my0E_p_Inside.b = &my0E_p;
	my0E_p_Inside.isOpen = false;
	////.f = &;

	my0E_o_Inside.path = "my0E_o_Inside";
	my0E_o_Inside.b = &my0E_o;
	my0E_o_Inside.isOpen = false;
	////.f = &;

	my0E_n_Inside.path = "my0E_n_Inside";
	my0E_n_Inside.b = &my0E_n;
	my0E_n_Inside.isOpen = false;
	////.f = &;

	my0E_m_Inside.path = "my0E_m_Inside";
	my0E_m_Inside.b = &my0E_m;
	my0E_m_Inside.isOpen = false;
	////.f = &;

	my0W_f_Inside.path = "my0W_f_Inside";
	my0W_f_Inside.b = &my0W_f;
	my0W_f_Inside.isOpen = false;
	////.f = &;

	my0W_e_Inside.path = "my0W_e_Inside";
	my0W_e_Inside.b = &my0W_e;
	my0W_e_Inside.isOpen = false;
	////.f = &;

	my0W_d_Inside.path = "my0W_d_Inside";
	my0W_d_Inside.b = &my0W_d;
	my0W_d_Inside.isOpen = false;
	////.f = &;

	my0W_c_Inside.path = "my0W_c_Inside";
	my0W_c_Inside.b = &my0W_c;
	my0W_c_Inside.isOpen = false;
	////.f = &;

	my0W_b_Inside.path = "my0W_b_Inside";
	my0W_b_Inside.b = &my0W_b;
	my0W_b_Inside.isOpen = false;
	////.f = &;

	my0W_a_Inside.path = "my0W_a_Inside";
	my0W_a_Inside.b = &my0W_a;
	my0W_a_Inside.isOpen = false;
	////.f = &;

	my0S_L_Inside.path = "my0S_L_Inside";
	my0S_L_Inside.b = &my0S_L;
	my0S_L_Inside.isOpen = false;
	////.f = &;

	my0S_k_Inside.path = "my0S_k_Inside";
	my0S_k_Inside.b = &my0S_k;
	my0S_k_Inside.isOpen = false;
	////.f = &;

	my0S_j_Inside.path = "my0S_j_Inside";
	my0S_j_Inside.b = &my0S_j;
	my0S_j_Inside.isOpen = false;
	////.f = &;

	my0S_i_Inside.path = "my0S_i_Inside";
	my0S_i_Inside.b = &my0S_i;
	my0S_i_Inside.isOpen = false;
	////.f = &;

	my0S_h_Inside.path = "my0S_h_Inside";
	my0S_h_Inside.b = &my0S_h;
	my0S_h_Inside.isOpen = false;
	////.f = &;

	my0S_g_Inside.path = "my0S_g_Inside";
	my0S_g_Inside.b = &my0S_g;
	my0S_g_Inside.isOpen = false;
	////.f = &;

	my0S_f_Inside.path = "my0S_f_Inside";
	my0S_f_Inside.b = &my0S_f;
	my0S_f_Inside.isOpen = false;
	////.f = &;

	my0S_e_Inside.path = "my0S_e_Inside";
	my0S_e_Inside.b = &my0S_e;
	my0S_e_Inside.isOpen = false;
	////.f = &;

	my0S_d_Inside.path = "my0S_d_Inside";
	my0S_d_Inside.b = &my0S_d;
	my0S_d_Inside.isOpen = false;
	////.f = &;

	my0S_c_Inside.path = "my0S_c_Inside";
	my0S_c_Inside.b = &my0S_c;
	my0S_c_Inside.isOpen = false;
	////.f = &;

	my0S_b_Inside.path = "my0S_b_Inside";
	my0S_b_Inside.b = &my0S_b;
	my0S_b_Inside.isOpen = false;
	////.f = &;

	my0S_a_Inside.path = "my0S_a_Inside";
	my0S_a_Inside.b = &my0S_a;
	my0S_a_Inside.isOpen = false;
	////.f = &;

	my0N_r_Inside.path = "my0N_r_Inside";
	my0N_r_Inside.b = &my0N_r;
	my0N_r_Inside.isOpen = false;
	////.f = &;

	my0N_q_Inside.path = "my0N_q_Inside";
	my0N_q_Inside.b = &my0N_q;
	my0N_q_Inside.isOpen = false;
	////.f = &;

	my0N_p_Inside.path = "my0N_p_Inside";
	my0N_p_Inside.b = &my0N_p;
	my0N_p_Inside.isOpen = false;
	////.f = &;

	my0N_o_Inside.path = "my0N_o_Inside";
	my0N_o_Inside.b = &my0N_o;
	my0N_o_Inside.isOpen = false;
	////.f = &;

	my0N_n_Inside.path = "my0N_n_Inside";
	my0N_n_Inside.b = &my0N_n;
	my0N_n_Inside.isOpen = false;
	////.f = &;

	my0N_m_Inside.path = "my0N_m_Inside";
	my0N_m_Inside.b = &my0N_m;
	my0N_m_Inside.isOpen = false;
	////.f = &;

	my0N_L_Inside.path = "my0N_L_Inside";
	my0N_L_Inside.b = &my0N_L;
	my0N_L_Inside.isOpen = false;
	////.f = &;

	my0N_k_Inside.path = "my0N_k_Inside";
	my0N_k_Inside.b = &my0N_k;
	my0N_k_Inside.isOpen = false;
	////.f = &;

	my0N_j_Inside.path = "my0N_j_Inside";
	my0N_j_Inside.b = &my0N_j;
	my0N_j_Inside.isOpen = false;
	////.f = &;

	my0N_i_Inside.path = "my0N_i_Inside";
	my0N_i_Inside.b = &my0N_i;
	my0N_i_Inside.isOpen = false;
	////.f = &;

	my0N_h_Inside.path = "my0N_h_Inside";
	my0N_h_Inside.b = &my0N_h;
	my0N_h_Inside.isOpen = false;
	////.f = &;

	my0N_g_Inside.path = "my0N_g_Inside";
	my0N_g_Inside.b = &my0N_g;
	my0N_g_Inside.isOpen = false;
	////.f = &;
#pragma endregion

#pragma region BETWEEN_AREAS_MIDS
	myMid_HN.path = "myMid_HN";
	myMid_HN.f = &myMid_JP;
	myMid_HN.b = &my0S_j;
	myMid_HN.l = &myH0_wayIn;
	myMid_HN.r = &myN0_sewer;

	myMid_JP.path = "myMid_JP";
	myMid_JP.f = &myMid_LR;
	myMid_JP.b = &myMid_HN;
	myMid_JP.l = &myJ0_wayIn;
	myMid_JP.r = &myP0_sewer;

	myMid_LR.path = "myMid_LR";
	myMid_LR.f = &my0N_o;
	myMid_LR.b = &myMid_JP;
	myMid_LR.l = &myL0_wayIn;
	myMid_LR.r = &myR0_sewer;

	myMid_EK.path = "myMid_EK";
	myMid_EK.f = &my0N_i;
	myMid_EK.b = &myMid_CI;
	myMid_EK.l = &myE0_sewer;
	myMid_EK.r = &myK0_wayIn;

	myMid_CI.path = "myMid_CI";
	myMid_CI.f = &myMid_EK;
	myMid_CI.b = &myMid_AG;
	myMid_CI.l = &myC0_sewer;
	myMid_CI.r = &myI0_wayIn;

	myMid_AG.path = "myMid_AG";
	myMid_AG.f = &myMid_CI;
	myMid_AG.b = &my0S_d;
	myMid_AG.l = &myA0_sewer;
	myMid_AG.r = &myG0_wayIn;
	myMid_AG.items.push_back(stone);
#pragma endregion

#pragma region VENTS
	my0E_r.path = "my0E_r";
	my0E_r.f = &my0E_r_Inside;
	my0E_r.b = &myR0_wayIn;
	my0E_r.l = &my0N_r;
	my0E_r.r = &my0E_q;
	//my0E_r.isOpen = false; // opens on water for clothes time
	my0E_r.vadermarke = Vadermarke::East;

	my0E_q.path = "my0E_q";
	my0E_q.f = &my0E_q_Inside;
	my0E_q.b = &myQ0_wayIn;
	my0E_q.l = &my0E_r;
	my0E_q.r = &my0E_p;
	//my0E_q.isOpen = false;
	my0E_q.vadermarke = Vadermarke::East;

	my0E_p.path = "my0E_p";
	my0E_p.f = &my0E_p_Inside;
	my0E_p.b = &myP0_wayIn;
	my0E_p.l = &my0E_q;
	my0E_p.r = &my0E_o;
	//my0E_p.isOpen = false;
	my0E_p.vadermarke = Vadermarke::East;

	my0E_o.path = "my0E_o";
	my0E_o.f = &my0E_o_Inside;
	my0E_o.b = &myO0_wayIn;
	my0E_o.l = &my0E_p;
	my0E_o.r = &my0E_n;
	//my0E_o.isOpen = false;
	my0E_o.vadermarke = Vadermarke::East;

	my0E_n.path = "my0E_n";
	my0E_n.f = &my0E_n_Inside;
	my0E_n.b = &myN0_wayIn;
	my0E_n.l = &my0E_o;
	my0E_n.r = &my0E_m;
	//my0E_n.isOpen = false;
	my0E_n.vadermarke = Vadermarke::East;

	my0E_m.path = "my0E_m";
	my0E_m.f = &my0E_m_Inside;
	my0E_m.b = &myM0_wayIn;
	my0E_m.l = &my0E_n;
	my0E_m.r = &my0S_L;
	//my0E_m.isOpen = false;
	my0E_m.vadermarke = Vadermarke::East;

	my0W_f.path = "my0W_f";
	my0W_f.f = &my0W_f_Inside;
	my0W_f.b = &myF0_wayIn;
	my0W_f.l = &my0W_e;
	my0W_f.r = &my0N_g;
	//my0W_f.isOpen = false;
	my0W_f.vadermarke = Vadermarke::West;

	my0W_e.path = "my0W_e";
	my0W_e.f = &my0W_e_Inside;
	my0W_e.b = &myE0_wayIn;
	my0W_e.l = &my0W_d;
	my0W_e.r = &my0W_f;
	//my0W_e.isOpen = false;
	my0W_e.vadermarke = Vadermarke::West;

	my0W_d.path = "my0W_d";
	my0W_d.f = &my0W_d_Inside;
	my0W_d.b = &myD0_wayIn;
	my0W_d.l = &my0W_c;
	my0W_d.r = &my0W_e;
	//my0W_d.isOpen = false;
	my0W_d.vadermarke = Vadermarke::West;

	my0W_c.path = "my0W_c";
	my0W_c.f = &my0W_c_Inside;
	my0W_c.b = &myC0_wayIn;
	my0W_c.l = &my0W_b;
	my0W_c.r = &my0W_d;
	//my0W_c.isOpen = false;
	my0W_c.vadermarke = Vadermarke::West;

	my0W_b.path = "my0W_b";
	my0W_b.f = &my0W_b_Inside;
	my0W_b.b = &myB0_wayIn;
	my0W_b.l = &my0W_a;
	my0W_b.r = &my0W_c;
	//my0W_b.isOpen = false;
	my0W_b.vadermarke = Vadermarke::West;

	my0W_a.path = "my0W_a";
	my0W_a.f = &my0W_a_Inside;
	my0W_a.b = &myA0_wayIn;
	my0W_a.l = &my0S_a;
	my0W_a.r = &my0W_b;
	//my0W_a.isOpen = false;
	my0W_a.vadermarke = Vadermarke::West;

	my0S_L.path = "my0S_L";
	my0S_L.f = &my0S_L_Inside;
	my0S_L.l = &my0E_m;
	my0S_L.r = &my0S_k;
	//my0S_L.isOpen = false;
	my0S_L.vadermarke = Vadermarke::South;

	my0S_k.path = "my0S_k";
	my0S_k.f = &my0S_k_Inside;
	my0S_k.b = &myM0_sewer;
	my0S_k.l = &my0S_L;
	my0S_k.r = &my0S_j;
	//my0S_k.isOpen = false;
	my0S_k.vadermarke = Vadermarke::South;

	my0S_j.path = "my0S_j";
	my0S_j.f = &my0S_j_Inside;
	my0S_j.b = &myMid_HN;
	my0S_j.l = &my0S_k;
	my0S_j.r = &my0S_i;
	//my0S_j.isOpen = false;
	my0S_j.vadermarke = Vadermarke::South;

	my0S_i.path = "my0S_i";
	my0S_i.f = &my0S_i_Inside;
	my0S_i.l = &my0S_j;
	my0S_i.r = &my0S_h;
	//my0S_i.isOpen = false;
	my0S_i.vadermarke = Vadermarke::South;

	my0S_h.path = "my0S_h";
	my0S_h.f = &my0S_h_Inside;
	my0S_h.l = &my0S_i;
	my0S_h.r = &my0S_g;
	//my0S_h.isOpen = false;
	my0S_h.vadermarke = Vadermarke::South;

	my0S_g.path = "my0S_g";
	my0S_g.f = &my0S_g_Inside;
	my0S_g.l = &my0S_h;
	my0S_g.r = &my0S_f;
	//my0S_g.isOpen = false;
	my0S_g.vadermarke = Vadermarke::South;

	my0S_f.path = "my0S_f";
	my0S_f.f = &my0S_f_Inside;
	my0S_f.b = &myG0_wayIn;
	my0S_f.l = &my0S_g;
	my0S_f.r = &my0S_e;
	//my0S_f.isOpen = false;
	my0S_f.vadermarke = Vadermarke::South;

	my0S_e.path = "my0S_e";
	my0S_e.f = &my0S_e_Inside;
	my0S_e.l = &my0S_f;
	my0S_e.r = &my0S_d;
	//my0S_e.isOpen = false;
	my0S_e.vadermarke = Vadermarke::South;

	my0S_d.path = "my0S_d";
	my0S_d.f = &my0S_d_Inside;
	my0S_d.b = &myMid_AG;
	my0S_d.l = &my0S_e;
	my0S_d.r = &my0S_c;
	//my0S_d.isOpen = false;
	my0S_d.vadermarke = Vadermarke::South;

	my0S_c.path = "my0S_c";
	my0S_c.f = &my0S_c_Inside;
	my0S_c.l = &my0S_d;
	my0S_c.r = &my0S_b;
	//my0S_c.isOpen = false;
	my0S_c.vadermarke = Vadermarke::South;

	my0S_b.path = "my0S_b";
	my0S_b.f = &my0S_b_Inside;
	my0S_b.l = &my0S_c;
	my0S_b.r = &my0S_a;
	//my0S_b.isOpen = false;
	my0S_b.vadermarke = Vadermarke::South;

	my0S_a.path = "my0S_a";
	my0S_a.f = &my0S_a_Inside;
	my0S_a.b = &myA0_sewer;
	my0S_a.l = &my0S_b;
	my0S_a.r = &my0W_a;
	//my0S_a.isOpen = false;
	my0S_a.vadermarke = Vadermarke::South;

	my0N_r.path = "my0N_r";
	my0N_r.f = &my0N_r_Inside;
	my0N_r.b = &myR0_sewer;
	my0N_r.l = &my0N_q;
	my0N_r.r = &my0E_r;
	//my0N_r.isOpen = false;
	my0N_r.vadermarke = Vadermarke::North;

	my0N_q.path = "my0N_q";
	my0N_q.f = &my0N_q_Inside;
	my0N_q.l = &my0N_p;
	my0N_q.r = &my0N_r;
	//my0N_q.isOpen = false;
	my0N_q.vadermarke = Vadermarke::North;

	my0N_p.path = "my0N_p";
	my0N_p.f = &my0N_p_Inside;
	my0N_p.l = &my0N_o;
	my0N_p.r = &my0N_q;
	//my0N_p.isOpen = false;
	my0N_p.vadermarke = Vadermarke::North;

	my0N_o.path = "my0N_o";
	my0N_o.f = &my0N_o_Inside;
	my0N_o.b = &myMid_LR;
	my0N_o.l = &my0N_n;
	my0N_o.r = &my0N_p;
	//my0N_o.isOpen = false;
	my0N_o.vadermarke = Vadermarke::North;

	my0N_n.path = "my0N_n";
	my0N_n.f = &my0N_n_Inside;
	my0N_n.l = &my0N_m;
	my0N_n.r = &my0N_o;
	//my0N_n.isOpen = false;
	my0N_n.vadermarke = Vadermarke::North;

	my0N_m.path = "my0N_m";
	my0N_m.f = &my0N_m_Inside;
	my0N_m.b = &myL0_wayIn;
	my0N_m.l = &my0N_L;
	my0N_m.r = &my0N_n;
	//my0N_m.isOpen = false;
	my0N_m.vadermarke = Vadermarke::North;

	my0N_L.path = "my0N_L";
	my0N_L.f = &my0N_L_Inside;
	my0N_L.l = &my0N_k;
	my0N_L.r = &my0N_m;
	//my0N_L.isOpen = false;
	my0N_L.vadermarke = Vadermarke::North;

	my0N_k.path = "my0N_k";
	my0N_k.f = &my0N_k_Inside;
	my0N_k.b = &myL0_sewer;
	my0N_k.l = &my0N_j;
	my0N_k.r = &my0N_L;
	//my0N_k.isOpen = false;
	my0N_k.vadermarke = Vadermarke::North;

	my0N_j.path = "my0N_j";
	my0N_j.f = &my0N_j_Inside;
	my0N_j.l = &my0N_i;
	my0N_j.r = &my0N_k;
	//my0N_j.isOpen = false;
	my0N_j.vadermarke = Vadermarke::North;

	my0N_i.path = "my0N_i";
	my0N_i.f = &my0N_i_Inside;
	my0N_i.b = &myMid_EK;
	my0N_i.l = &my0N_h;
	my0N_i.r = &my0N_j;
	//my0N_i.isOpen = false;
	my0N_i.vadermarke = Vadermarke::North;

	my0N_h.path = "my0N_h";
	my0N_h.f = &my0N_h_Inside;
	my0N_h.l = &my0N_g;
	my0N_h.r = &my0N_i;
	//my0N_h.isOpen = false;
	my0N_h.vadermarke = Vadermarke::North;

	my0N_g.path = "my0N_g";
	my0N_g.f = &my0N_g_Inside;
	my0N_g.b = &myF0_sewer;
	my0N_g.l = &my0W_f;
	my0N_g.r = &my0N_h;
	//my0N_g.isOpen = false;
	my0N_g.vadermarke = Vadermarke::North;
#pragma endregion

#pragma region SEWERS
	myR0_sewer.path = "myR0_sewer";
	//myR0_sewer.f = &;
	myR0_sewer.b = &myMid_LR;
	myR0_sewer.l = &my0N_r;
	myR0_sewer.r = &myQ0_sewer;

	myQ0_sewer.path = "myQ0_sewer";
	//myQ0_sewer.f = &;
	myQ0_sewer.l = &myR0_sewer;
	myQ0_sewer.r = &myP0_sewer;

	myP0_sewer.path = "myP0_sewer";
	//myP0_sewer.f = &;
	myP0_sewer.b = &myMid_JP;
	myP0_sewer.l = &myQ0_sewer;
	myP0_sewer.r = &myO0_sewer;

	myO0_sewer.path = "myO0_sewer";
	//myO0_sewer.f = &;
	myO0_sewer.l = &myP0_sewer;
	myO0_sewer.r = &myN0_sewer;

	myN0_sewer.path = "myN0_sewer";
	//myN0_sewer.f = &;
	myN0_sewer.b = &myMid_HN;
	myN0_sewer.l = &myO0_sewer;
	myN0_sewer.r = &myM0_sewer;

	myM0_sewer.path = "myM0_sewer";
	//myM0_sewer.f = &;
	myM0_sewer.l = &myN0_sewer;
	myM0_sewer.r = &my0S_k;

	myL0_sewer.path = "myL0_sewer";
	//myL0_sewer.f = &;
	myL0_sewer.l = &my0N_L;
	myL0_sewer.r = &myK0_wayIn;

	myK0_sewer.path = "myK0_sewer";
	//myK0_sewer.f = &;
	myK0_sewer.l = &myJ0_wayIn;
	myK0_sewer.r = &myL0_wayIn;

	myJ0_sewer.path = "myJ0_sewer";
	//myJ0_sewer.f = &;
	myJ0_sewer.l = &myK0_wayIn;
	myJ0_sewer.r = &myI0_wayIn;

	myI0_sewer.path = "myI0_sewer";
	myI0_sewer.l = &myH0_wayIn;
	myI0_sewer.r = &myJ0_wayIn;

	myH0_sewer.path = "myH0_sewer";
	myH0_sewer.l = &myI0_wayIn;
	myH0_sewer.r = &myG0_wayIn;

	// G0 sewer

	myF0_sewer.path = "myF0_sewer";
	myF0_sewer.l = &myE0_sewer;
	myF0_sewer.r = &my0N_g;

	myE0_sewer.path = "myE0_sewer";
	myE0_sewer.b = &myMid_EK;
	myE0_sewer.l = &myD0_sewer;
	myE0_sewer.r = &myF0_sewer;

	myD0_sewer.path = "myD0_sewer";
	myD0_sewer.l = &myC0_sewer;
	myD0_sewer.r = &myE0_sewer;

	myC0_sewer.path = "myC0_sewer";
	myC0_sewer.b = &myMid_CI;
	myC0_sewer.l = &myB0_sewer;
	myC0_sewer.r = &myD0_sewer;

	myB0_sewer.path = "myB0_sewer";
	myB0_sewer.l = &myA0_sewer;
	myB0_sewer.r = &myC0_sewer;

	myA0_sewer.path = "myA0_sewer";
	myA0_sewer.b = &myMid_AG;
	myA0_sewer.l = &my0S_a;
	myA0_sewer.r = &myB0_sewer;
#pragma endregion

#pragma region CUBES
	myR0_wayIn.path = "myR0_wayIn";
	//myR0_wayIn.f = &;
	myR0_wayIn.b = &my0E_r;
	myR0_wayIn.l = &myQ0_wayIn;
	myR0_wayIn.r = &my0N_r;

	myQ0_wayIn.path = "myQ0_wayIn";
	//myQ0_wayIn.f = &;
	myQ0_wayIn.b = &my0E_q;
	myQ0_wayIn.l = &myP0_wayIn;
	myQ0_wayIn.r = &myR0_wayIn;

	myP0_wayIn.path = "myP0_wayIn";
	//myP0_wayIn.f = &;
	myP0_wayIn.b = &my0E_p;
	myP0_wayIn.l = &myO0_wayIn;
	myP0_wayIn.r = &myQ0_wayIn;

	myO0_wayIn.path = "myO0_wayIn";
	//myO0_wayIn.f = &;
	myO0_wayIn.b = &my0E_o;
	myO0_wayIn.l = &myN0_wayIn;
	myO0_wayIn.r = &myP0_wayIn;

	myN0_wayIn.path = "myN0_wayIn";
	//myN0_wayIn.f = &;
	myN0_wayIn.b = &my0E_n;
	myN0_wayIn.l = &myM0_wayIn;
	myN0_wayIn.r = &myO0_wayIn;

	myM0_wayIn.path = "myM0_wayIn";
	//myM0_wayIn.f = &;
	myM0_wayIn.b = &my0E_m;
	myM0_wayIn.l = &my0S_L;
	myM0_wayIn.r = &myN0_wayIn;

	myL0_wayIn.path = "myL0_wayIn";
	//myL0_wayIn.f = &;
	myL0_wayIn.b = &myMid_LR;
	myL0_wayIn.l = &myK0_sewer;
	myL0_wayIn.r = &my0N_m;

	myK0_wayIn.path = "myK0_wayIn";
	//myK0_wayIn.f = &;
	myK0_wayIn.b = &myMid_EK;
	myK0_wayIn.l = &myL0_sewer;
	myK0_wayIn.r = &myJ0_sewer;

	myJ0_wayIn.path = "myJ0_wayIn";
	//myJ0_wayIn.f = &;
	myJ0_wayIn.b = &myMid_JP;
	myJ0_wayIn.l = &myI0_sewer;
	myJ0_wayIn.r = &myK0_sewer;

	myI0_wayIn.path = "myI0_wayIn";
	//myI0_wayIn.f = &;
	myI0_wayIn.b = &myMid_CI;
	myI0_wayIn.l = &myJ0_sewer;
	myI0_wayIn.r = &myH0_sewer;

	myH0_wayIn.path = "myH0_wayIn";
	//myH0_wayIn.f = &;
	myH0_wayIn.b = &myMid_HN;
	myH0_wayIn.l = &myG0_sewer;
	myH0_wayIn.r = &myI0_sewer;

	myF0_wayIn.path = "myF0_wayIn";
	//myF0_wayIn.f = &;
	myF0_wayIn.b = &my0W_f;
	myF0_wayIn.l = &my0N_g;
	myF0_wayIn.r = &myE0_wayIn;

	myE0_wayIn.path = "myE0_wayIn";
	//myE0_wayIn.f = &;
	myE0_wayIn.b = &my0W_e;
	myE0_wayIn.l = &myF0_wayIn;
	myE0_wayIn.r = &myD0_wayIn;

	myD0_wayIn.path = "myD0_wayIn";
	//myD0_wayIn.f = &;
	myD0_wayIn.b = &my0W_d;
	myD0_wayIn.l = &myE0_wayIn;
	myD0_wayIn.r = &myC0_wayIn;

	myC0_wayIn.path = "myC0_wayIn";
	//myC0_wayIn.f = &;
	myC0_wayIn.b = &my0W_c;
	myC0_wayIn.l = &myD0_wayIn;
	myC0_wayIn.r = &myB0_wayIn;

	myB0_wayIn.path = "myB0_wayIn";
	//myB0_wayIn.f = &;
	myB0_wayIn.b = &my0W_b;
	myB0_wayIn.l = &myC0_wayIn;
	myB0_wayIn.r = &myA0_wayIn;

	myA0_wayIn.path = "myA0_wayIn";
	//myA0_wayIn.f = &;
	myA0_wayIn.b = &my0W_a;
	myA0_wayIn.l = &myB0_wayIn;
	myA0_wayIn.r = &my0S_a;
#pragma endregion

//
#pragma region PUSH_BACK_LOCS
	myLocations.push_back(&myG0_inTopBed);
	myLocations.push_back(&myG0_bothBeds);
	myLocations.push_back(&myG0_kitchen_and_wayOut);
	myLocations.push_back(&myG0_desk);
	myLocations.push_back(&myG0_desk_diary);
	myLocations.push_back(&myG0_toilet);
	myLocations.push_back(&myG0_wardrobe);
	myLocations.push_back(&myG0_clock);

	myLocations.push_back(&myG0_ladderToG0);
	myLocations.push_back(&myG0_ladderToCistern);
	myLocations.push_back(&myG0_corridorToG0);
	myLocations.push_back(&myG0_corridorToCistern);

	myLocations.push_back(&myA0_wayIn);
	myLocations.push_back(&myB0_wayIn);
	myLocations.push_back(&myC0_wayIn);
	myLocations.push_back(&myD0_wayIn);
	myLocations.push_back(&myE0_wayIn);
	myLocations.push_back(&myF0_wayIn);
	myLocations.push_back(&myG0_wayIn);
	myLocations.push_back(&myH0_wayIn);
	myLocations.push_back(&myI0_wayIn);
	myLocations.push_back(&myJ0_wayIn);
	myLocations.push_back(&myK0_wayIn);
	myLocations.push_back(&myL0_wayIn);
	myLocations.push_back(&myM0_wayIn);
	myLocations.push_back(&myN0_wayIn);
	myLocations.push_back(&myO0_wayIn);
	myLocations.push_back(&myP0_wayIn);
	myLocations.push_back(&myQ0_wayIn);
	myLocations.push_back(&myR0_wayIn);

	myLocations.push_back(&myA0_sewer);
	myLocations.push_back(&myB0_sewer);
	myLocations.push_back(&myC0_sewer);
	myLocations.push_back(&myD0_sewer);
	myLocations.push_back(&myE0_sewer);
	myLocations.push_back(&myF0_sewer);
	myLocations.push_back(&myG0_sewer);
	myLocations.push_back(&myH0_sewer);
	myLocations.push_back(&myI0_sewer);
	myLocations.push_back(&myJ0_sewer);
	myLocations.push_back(&myK0_sewer);
	myLocations.push_back(&myL0_sewer);
	myLocations.push_back(&myM0_sewer);
	myLocations.push_back(&myN0_sewer);
	myLocations.push_back(&myO0_sewer);
	myLocations.push_back(&myP0_sewer);
	myLocations.push_back(&myQ0_sewer);
	myLocations.push_back(&myR0_sewer);

	myLocations.push_back(&my0N_g);
	myLocations.push_back(&my0N_h);
	myLocations.push_back(&my0N_i);
	myLocations.push_back(&my0N_j);
	myLocations.push_back(&my0N_k);
	myLocations.push_back(&my0N_L);
	myLocations.push_back(&my0N_m);
	myLocations.push_back(&my0N_n);
	myLocations.push_back(&my0N_o);
	myLocations.push_back(&my0N_p);
	myLocations.push_back(&my0N_q);
	myLocations.push_back(&my0N_r);
	myLocations.push_back(&my0S_a);
	myLocations.push_back(&my0S_b);
	myLocations.push_back(&my0S_c);
	myLocations.push_back(&my0S_d);
	myLocations.push_back(&my0S_e);
	myLocations.push_back(&my0S_f);
	myLocations.push_back(&my0S_g);
	myLocations.push_back(&my0S_h);
	myLocations.push_back(&my0S_i);
	myLocations.push_back(&my0S_j);
	myLocations.push_back(&my0S_k);
	myLocations.push_back(&my0S_L);
	myLocations.push_back(&my0W_a);
	myLocations.push_back(&my0W_b);
	myLocations.push_back(&my0W_c);
	myLocations.push_back(&my0W_d);
	myLocations.push_back(&my0W_e);
	myLocations.push_back(&my0W_f);
	myLocations.push_back(&my0E_m);
	myLocations.push_back(&my0E_n);
	myLocations.push_back(&my0E_o);
	myLocations.push_back(&my0E_p);
	myLocations.push_back(&my0E_q);
	myLocations.push_back(&my0E_r);

	myLocations.push_back(&my0N_g_Inside);
	myLocations.push_back(&my0N_h_Inside);
	myLocations.push_back(&my0N_i_Inside);
	myLocations.push_back(&my0N_j_Inside);
	myLocations.push_back(&my0N_k_Inside);
	myLocations.push_back(&my0N_L_Inside);
	myLocations.push_back(&my0N_m_Inside);
	myLocations.push_back(&my0N_n_Inside);
	myLocations.push_back(&my0N_o_Inside);
	myLocations.push_back(&my0N_p_Inside);
	myLocations.push_back(&my0N_q_Inside);
	myLocations.push_back(&my0N_r_Inside);
	myLocations.push_back(&my0S_a_Inside);
	myLocations.push_back(&my0S_b_Inside);
	myLocations.push_back(&my0S_c_Inside);
	myLocations.push_back(&my0S_d_Inside);
	myLocations.push_back(&my0S_e_Inside);
	myLocations.push_back(&my0S_f_Inside);
	myLocations.push_back(&my0S_g_Inside);
	myLocations.push_back(&my0S_h_Inside);
	myLocations.push_back(&my0S_i_Inside);
	myLocations.push_back(&my0S_j_Inside);
	myLocations.push_back(&my0S_k_Inside);
	myLocations.push_back(&my0S_L_Inside);
	myLocations.push_back(&my0W_a_Inside);
	myLocations.push_back(&my0W_b_Inside);
	myLocations.push_back(&my0W_c_Inside);
	myLocations.push_back(&my0W_d_Inside);
	myLocations.push_back(&my0W_e_Inside);
	myLocations.push_back(&my0W_f_Inside);
	myLocations.push_back(&my0E_m_Inside);
	myLocations.push_back(&my0E_n_Inside);
	myLocations.push_back(&my0E_o_Inside);
	myLocations.push_back(&my0E_p_Inside);
	myLocations.push_back(&my0E_q_Inside);
	myLocations.push_back(&my0E_r_Inside);

	myLocations.push_back(&myMid_AG);
	myLocations.push_back(&myMid_CI);
	myLocations.push_back(&myMid_EK);
	myLocations.push_back(&myMid_LR);
	myLocations.push_back(&myMid_JP);
	myLocations.push_back(&myMid_HN);
#pragma endregion
}

std::vector<Location*> CisternMap::GetNeighbours(Location* aCurrentLocation)
{
	std::vector<Location*> neighbourLocations;

	if (aCurrentLocation->r)
	{
		neighbourLocations.push_back(aCurrentLocation->r);
	}

	if (aCurrentLocation->f)
	{
		neighbourLocations.push_back(aCurrentLocation->f);
	}

	if (aCurrentLocation->l)
	{
		neighbourLocations.push_back(aCurrentLocation->l);
	}

	if (aCurrentLocation->b)
	{
		neighbourLocations.push_back(aCurrentLocation->b);
	}

	return neighbourLocations;
}

void CisternMap::FloodFillIsland(Location* aStartLocation, int anIslandID)
{
	std::queue<Location*> locationQueue;
	locationQueue.push(aStartLocation);
	aStartLocation->islandID = anIslandID;

	while (!locationQueue.empty())
	{
		Location* current = locationQueue.front();
		locationQueue.pop();

		for (Location* neighbor : GetNeighbours(current))
		{
			if (neighbor->islandID == -1)
			{
				neighbor->islandID = anIslandID;
				locationQueue.push(neighbor);
			}
		}
	}
}

Vadermarke CisternMap::ReachVadermarkeRecursive(Location* aStartLocation, unsigned anIt)
{
	if (!aStartLocation)
	{
		return Vadermarke::Count;
	}
	if (aStartLocation->vadermarke != Vadermarke::Count)
	{
		return aStartLocation->vadermarke;
	}
	if (!aStartLocation->f)
	{
		return Vadermarke::Count;
	}

	++anIt;

	if (anIt < 8)
	{
		if (aStartLocation->f->vadermarke != Vadermarke::Count)
		{
			return aStartLocation->f->vadermarke;
		}
		else
		{
			return ReachVadermarkeRecursive(aStartLocation->f, anIt);
		}
	}

	return Vadermarke::Count;
}

void CisternMap::NorthVentsOpenClose(Time& aCurrentTime)
{
	if (aCurrentTime.ourSS == 9 && aCurrentTime.ourTT == 9)
	{
			my0N_g_Inside.isOpen = true;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 11 && aCurrentTime.ourTT == 6)
	{
		my0N_g_Inside.isOpen = false;
			my0N_h_Inside.isOpen = true;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 13 && aCurrentTime.ourTT == 2)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
			my0N_i_Inside.isOpen = true;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 14 && aCurrentTime.ourTT == 9)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
			my0N_j_Inside.isOpen = true;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 16 && aCurrentTime.ourTT == 5)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
			my0N_k_Inside.isOpen = true;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 18 && aCurrentTime.ourTT == 2)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
			my0N_L_Inside.isOpen = true;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 19 && aCurrentTime.ourTT == 8)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
			my0N_m_Inside.isOpen = true;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 21 && aCurrentTime.ourTT == 5)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
			my0N_n_Inside.isOpen = true;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 23 && aCurrentTime.ourTT == 1)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
			my0N_o_Inside.isOpen = true;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 24 && aCurrentTime.ourTT == 8)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
			my0N_p_Inside.isOpen = true;
		my0N_q_Inside.isOpen = false;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 26 && aCurrentTime.ourTT == 4)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
			my0N_q_Inside.isOpen = true;
		my0N_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 28 && aCurrentTime.ourTT == 1)
	{
		my0N_g_Inside.isOpen = false;
		my0N_h_Inside.isOpen = false;
		my0N_i_Inside.isOpen = false;
		my0N_j_Inside.isOpen = false;
		my0N_k_Inside.isOpen = false;
		my0N_L_Inside.isOpen = false;
		my0N_m_Inside.isOpen = false;
		my0N_n_Inside.isOpen = false;
		my0N_o_Inside.isOpen = false;
		my0N_p_Inside.isOpen = false;
		my0N_q_Inside.isOpen = false;
			my0N_r_Inside.isOpen = true;
	}
}

void CisternMap::SouthVentsOpenClose(Time& aCurrentTime)
{
	if (aCurrentTime.ourSS == 57 && aCurrentTime.ourTT == 8)
	{
			my0S_a_Inside.isOpen = true;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 56 && aCurrentTime.ourTT == 1)
	{
		my0S_a_Inside.isOpen = false;
			my0S_b_Inside.isOpen = true;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 54 && aCurrentTime.ourTT == 5)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
			my0S_c_Inside.isOpen = true;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 52 && aCurrentTime.ourTT == 8)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
			my0S_d_Inside.isOpen = true;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 51 && aCurrentTime.ourTT == 2)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
			my0S_e_Inside.isOpen = true;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 49 && aCurrentTime.ourTT == 5)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
			my0S_f_Inside.isOpen = true;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 47 && aCurrentTime.ourTT == 9)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
			my0S_g_Inside.isOpen = true;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 46 && aCurrentTime.ourTT == 2)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
			my0S_h_Inside.isOpen = true;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 44 && aCurrentTime.ourTT == 6)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
			my0S_i_Inside.isOpen = true;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 42 && aCurrentTime.ourTT == 9)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
			my0S_j_Inside.isOpen = true;
		my0S_k_Inside.isOpen = false;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 41 && aCurrentTime.ourTT == 3)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
			my0S_k_Inside.isOpen = true;
		my0S_L_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 39 && aCurrentTime.ourTT == 6)
	{
		my0S_a_Inside.isOpen = false;
		my0S_b_Inside.isOpen = false;
		my0S_c_Inside.isOpen = false;
		my0S_d_Inside.isOpen = false;
		my0S_e_Inside.isOpen = false;
		my0S_f_Inside.isOpen = false;
		my0S_g_Inside.isOpen = false;
		my0S_h_Inside.isOpen = false;
		my0S_i_Inside.isOpen = false;
		my0S_j_Inside.isOpen = false;
		my0S_k_Inside.isOpen = false;
			my0S_L_Inside.isOpen = true;
	}
}

void CisternMap::EastVentsOpenClose(Time& aCurrentTime)
{
	if (aCurrentTime.ourSS == 38 && aCurrentTime.ourTT == 0)
	{
			my0E_m_Inside.isOpen = true;
		my0E_n_Inside.isOpen = false;
		my0E_o_Inside.isOpen = false;
		my0E_p_Inside.isOpen = false;
		my0E_q_Inside.isOpen = false;
		my0E_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 36 && aCurrentTime.ourTT == 3)
	{
		my0E_m_Inside.isOpen = false;
			my0E_n_Inside.isOpen = true;
		my0E_o_Inside.isOpen = false;
		my0E_p_Inside.isOpen = false;
		my0E_q_Inside.isOpen = false;
		my0E_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 34 && aCurrentTime.ourTT == 7)
	{
		my0E_m_Inside.isOpen = false;
		my0E_n_Inside.isOpen = false;
			my0E_o_Inside.isOpen = true;
		my0E_p_Inside.isOpen = false;
		my0E_q_Inside.isOpen = false;
		my0E_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 33 && aCurrentTime.ourTT == 0)
	{
		my0E_m_Inside.isOpen = false;
		my0E_n_Inside.isOpen = false;
		my0E_o_Inside.isOpen = false;
			my0E_p_Inside.isOpen = true;
		my0E_q_Inside.isOpen = false;
		my0E_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 31 && aCurrentTime.ourTT == 4)
	{
		my0E_m_Inside.isOpen = false;
		my0E_n_Inside.isOpen = false;
		my0E_o_Inside.isOpen = false;
		my0E_p_Inside.isOpen = false;
			my0E_q_Inside.isOpen = true;
		my0E_r_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 29 && aCurrentTime.ourTT == 7)
	{
		my0E_m_Inside.isOpen = false;
		my0E_n_Inside.isOpen = false;
		my0E_o_Inside.isOpen = false;
		my0E_p_Inside.isOpen = false;
		my0E_q_Inside.isOpen = false;
			my0E_r_Inside.isOpen = true;
	}
}

void CisternMap::WestVentsOpenClose(Time& aCurrentTime)
{
	if (aCurrentTime.ourSS == 0 && aCurrentTime.ourTT == 0)
	{
			my0W_a_Inside.isOpen = true;
		my0W_b_Inside.isOpen = false;
		my0W_c_Inside.isOpen = false;
		my0W_d_Inside.isOpen = false;
		my0W_e_Inside.isOpen = false;
		my0W_f_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 1 && aCurrentTime.ourTT == 7)
	{
		my0W_a_Inside.isOpen = false;
			my0W_b_Inside.isOpen = true;
		my0W_c_Inside.isOpen = false;
		my0W_d_Inside.isOpen = false;
		my0W_e_Inside.isOpen = false;
		my0W_f_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 3 && aCurrentTime.ourTT == 3)
	{
		my0W_a_Inside.isOpen = false;
		my0W_b_Inside.isOpen = false;
			my0W_c_Inside.isOpen = true;
		my0W_d_Inside.isOpen = false;
		my0W_e_Inside.isOpen = false;
		my0W_f_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 5 && aCurrentTime.ourTT == 0)
	{
		my0W_a_Inside.isOpen = false;
		my0W_b_Inside.isOpen = false;
		my0W_c_Inside.isOpen = false;
			my0W_d_Inside.isOpen = true;
		my0W_e_Inside.isOpen = false;
		my0W_f_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 6 && aCurrentTime.ourTT == 6)
	{
		my0W_a_Inside.isOpen = false;
		my0W_b_Inside.isOpen = false;
		my0W_c_Inside.isOpen = false;
		my0W_d_Inside.isOpen = false;
			my0W_e_Inside.isOpen = true;
		my0W_f_Inside.isOpen = false;
	}
	else if (aCurrentTime.ourSS == 8 && aCurrentTime.ourTT == 3)
	{
		my0W_a_Inside.isOpen = false;
		my0W_b_Inside.isOpen = false;
		my0W_c_Inside.isOpen = false;
		my0W_d_Inside.isOpen = false;
		my0W_e_Inside.isOpen = false;
			my0W_f_Inside.isOpen = true;
	}
}