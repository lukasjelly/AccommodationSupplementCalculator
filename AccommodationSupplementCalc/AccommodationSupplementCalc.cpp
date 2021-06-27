#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int func_income();
int func_area_search();
int func_living_situation();
int func_income_threshold(int area, int living_situation);
int func_reduction(int income, int income_threshold);
int func_acc_cost();
int func_entry_threshold(int living_situation);
int func_acc_supp(int living_situation, int area, int acc_cost, int entry_threshold);
int func_acc_supp_final(int acc_supp, int reduction);

//Global Variables
int i, j, output;

//Global Arrays
char situation[5][100] = {
	{"Single, 16+ years"},
	{"Married, civil union or de facto couple (without children)"},
	{"Married, civil union or de facto couple, 1+ children"},
	{"Sole parent, 1 child"},
	{"Sole parent, 2+ children"}
};

//Main program
int main() {
	char str[80];
	strcpy(str, "n");
	while (strcmp(str, "y") != 0) {
		int area = func_area_search();
		int income = func_income();
		int living_situation = func_living_situation();
		int income_threshold = func_income_threshold(area, living_situation);
		int reduction = func_reduction(income, income_threshold);
		int acc_cost = func_acc_cost();
		int entry_threshold = func_entry_threshold(living_situation);
		int acc_supp = func_acc_supp(living_situation, area, acc_cost, entry_threshold);
		int acc_supp_final = func_acc_supp_final(acc_supp, reduction);
		printf("\nArea Code: %d", area);
		printf("\nWeekly Income: $%d", income);
		printf("\nLiving situation: %s", situation[living_situation - 1]);
		printf("\nIncome Threshold: $%d", income_threshold);
		printf("\nReduction due to income: $%d", reduction);
		printf("\nAccommodation costs: $%d", acc_cost);
		printf("\nEntry threshold: $%d", entry_threshold);
		printf("\nAccommodation supplement entitlement before income reduction: $%d", acc_supp);
		printf("\n\nAccommodation supplement entitlement after income reduction: $%d", acc_supp_final);
		printf("\nExit program? y/n: ");
		gets_s(str);
	}

}

//Function to determine users weekly income
int func_income() {
	printf("Enter weekly income before tax: $");
	scanf("%d", &output);
	getchar();
	return output;
}

//Function to search for users area code
int func_area_search() {
	char area1[500][50] = { "Abbotts Park", "Akarana", "Albany", "Algies Bay", "Ambury", "Aorere", "Arahanga", "Arataki", "Arch Hill", "Ardmore", "Armour Bay", "Army Bay", "Arrowtown", "Arthurs Point", "Auckland Central East", "Auckland Central West", "Auckland Harbourside", "Avondale South", "Avondale West", "Awaruku", "Balmoral", "Baverstock Oaks", "Bayswater", "Beachhaven North", "Beachhaven South", "Beachlands-Maraetai", "Beaumont", "Bellevue", "Bethlehem", "Bethlehem East", "Birdwood East", "Birdwood West", "Birkdale North", "Birkdale South", "Birkenhead East", "Bleakhouse", "Bledisloe Park", "Blockhouse Bay", "Bombay", "Bremner", "Brookfield", "Browns Bay", "Buckland", "Buckland South", "Bucklands Beach South", "Bucklands and Eastern Beaches", "Burbank", "Burswood", "Campbells Bay", "Castor Bay", "Chelsea", "Clendon North", "Clendon South", "Clevedon", "Clover Park", "Cockle Bay", "Crown Hill", "Crum Park", "Dairy Flat-Redvale", "Dannemora", "Dingwall", "Doncaster", "Donegal Park", "Drury", "Durham Green", "Eden Road-Hill Top", "Eden Terrace", "Edgewater", "Edmonton", "Ellerslie North", "Ellerslie South", "Elsmore Park", "Epsom Central", "Epsom North", "Epsom South", "Fairburn", "Fairdene", "Fairview", "Favona North", "Favona South", "Favona West", "Ferguson", "Ferndale", "Forrest Hill", "Frankton", "Freemans Bay", "Fruitvale", "Gate Pa", "Glamorgan", "Glen Eden East", "Glen Innes East", "Glen Innes North", "Glen Innes West", "Glenavon", "Glenbrook", "Glendene North", "Glendene South", "Glendhu", "Glendowie", "Glenfield Central", "Glenfield North", "Golfland", "Grafton East", "Grafton West", "Grange", "Gravatt", "Green Bay", "Greenhithe", "Greenmount", "Greerton", "Grey Lynn East", "Grey Lynn West", "Gulf Harbour", "Hairini", "Half Moon Bay", "Hamlin", "Harania East", "Harania North", "Harania West", "Hatfields Beach", "Hauraki", "Helensville", "Helensville South", "Henderson North", "Henderson South", "Henderson West", "Herald", "Herne Bay", "Highbrook", "Highland Park", "Hillpark", "Hillsborough East", "Hillsborough West", "Hingaia", "Hobsonville East", "Hobsonville South", "Homai East", "Homai West", "Howick Central", "Howick South", "Howick West", "Huapai", "Hunua", "Hyperion", "Judea", "Kaipatiki", "Kairua", "Kaitemako", "Karekare", "Kaukapakapa", "Kaukapakapa Rural", "Kauri Park", "Kaurilands", "Kelston Central", "Kelvin Heights", "Kilkenny", "Kingdale", "Kingseat", "Kingsland", "Kohimarama East", "Kohimarama West", "Kohuora", "Konini", "Kumeu East", "Kumeu West", "Laingholm", "Lake Pupuke", "Leabank", "Long Bay", "Lucken Point", "Lynfield North", "Lynfield South", "Lynnmall", "Mahurangi", "Mairangi Bay", "Mangere Bridge", "Mangere Central", "Mangere East", "Mangere South", "Mangere Station", "Manly", "Manukau Central", "Manurewa Central", "Manurewa East", "Mascot", "Massey Park", "Massey West", "Matapihi", "Matipo", "Matua", "Maungatapu", "Maungawhau", "McLaren Park", "Mcleod", "Meadowbank North", "Meadowbank South", "Meadowland", "Mellons Bay", "Middlemore", "Mill Road", "Millhouse", "Mission Bay", "Mission Heights", "Monarch Park", "Motuopae Island", "Mt Albert Central", "Mt Eden East", "Mt Eden North", "Mt Eden South", "Mt Hobson", "Mt Maunganui North", "Mt St John", "Mt Victoria", "Mt Wellington Domain", "Mt Wellington North", "Mt Wellington South", "Mt Wellington West", "Muriwai Beach", "Muriwai Valley", "Murrays Bay", "Murvale", "Narrow Neck", "New Lynn North", "New Lynn South", "New Windsor", "Newmarket", "Newton", "North Harbour East", "North Harbour West", "Northcote South", "Northcross", "Oaktree", "Ocean View", "Ohauiti-Ngapeke", "Omanu", "Omokoroa", "One Tree Hill Central", "One Tree Hill East", "Onehunga North East", "Onehunga North West", "Onehunga South East", "Onehunga South West", "Opaheke", "Opanuku", "Opuawhanga", "Orakei North", "Orakei South", "Oranga", "Oratia", "Oratia West", "Orewa", "Orewa West", "Ormiston", "Otahuhu East", "Otahuhu North", "Otahuhu West", "Otara East", "Otara North", "Otara South", "Otara West", "Otimai", "Otumoetai North", "Otumoetai South", "Owairaka East", "Owairaka West", "Pacific View", "Paerata-Cape Hill", "Pahurehure", "Pakuranga Central", "Pakuranga East", "Pakuranga North", "Palm Beach", "Palm Heights", "Palm Springs", "Panmure Basin", "Papakura Central", "Papakura East", "Papakura North", "Papakura North East", "Papakura South", "Papamoa Beach East", "Papatoetoe Central", "Papatoetoe East", "Papatoetoe North", "Papatoetoe West", "Parakai Urban", "Paremoremo East", "Paremoremo West", "Parnell East", "Parnell West", "Parrs Park", "Parrs Park West", "Patumahoe", "Penrose", "Pigeon Mountain North", "Pigeon Mountain South", "Pinehill", "Poike", "Point Chevalier East", "Point Chevalier South", "Point Chevalier West", "Point England", "Point View", "Pokeno", "Ponsonby East", "Ponsonby West", "Puhinui North", "Puhinui South", "Pukekohe North", "Pukekohe West", "Pukeoware", "Pyes Pa", "Queenstown Bay", "Queenstown Hill", "Randwick Park", "Ranui Domain", "Ranui South", "Red Beach East", "Red Beach West", "Red Hill", "Redoubt", "Redoubt East", "Redoubt North", "Redoubt South", "Remuera South", "Remuera West", "Rewarewa", "Rewiti", "Riverhead", "Riverhead Urban", "Roberton", "Rongomai", "Rosebank", "Rosehill", "Rothesay Bay", "Rowandale", "Royal Heights", "Royal Oak", "Royal Road West", "Runciman", "Sandringham East", "Sandringham North", "Sandringham West", "Seacliffe", "Shelly Park", "Sherbourne", "Silverdale Central", "Silverdale North", "Silverdale South", "Snells Beach", "South Waiuku", "Springleigh", "St Heliers", "St Johns", "St Lukes", "St Lukes North", "St Marys", "Stanley Bay", "Stanmore Bay East", "Stanmore Bay West", "Starling Park", "Stillwater", "Stonefields", "Sturges North", "Sulphur Point", "Sunnybrae", "Sunnyhills", "Sunnynook", "Sunnyvale", "Sunshine Bay", "Surrey Crescent", "Swanson", "Swanson South", "Tahekeroa", "Takanini North", "Takanini South", "Takanini West", "Takapuna Central", "Tamaki", "Tangutu", "Target Road", "Taupaki", "Tauranga Central", "Tauranga Hospital", "Tauranga South", "Te Atatu Central", "Te Maunga", "Te Papapa", "Te Puna", "Te Reti", "Three Kings", "Titirangi South", "Torbay", "Totara Heights", "Tuakau", "Tuff Crater", "Turanga", "Unsworth Heights", "Urlich", "Vipond", "Viscount", "Wade Heads", "Waiake", "Waiata", "Waiheke Island", "Waikowhai East", "Waikowhai West", "Waima", "Waimauku", "Waimumu North", "Waimumu South", "Waipareira West", "Waitakere", "Waitakere West", "Waitaramoa", "Waiuku East", "Waiuku West", "Waiwera", "Wakeling", "Walmsley", "Wanaka", "Warkworth", "Waterview", "Wattle Farm", "Weiti River", "Welcome Bay East", "Welcome Bay West", "Wesley", "West Harbour", "Westgate", "Westlake", "Westmere", "Weymouth East", "Weymouth West", "Whangapouri Creek", "Whenuapai West", "Windsor Park", "Windy Ridge", "Wiri", "Witheford", "Woodglen", "Wymondley", "Yatton Park" };
	char area2[700][50] = { "Abbey Caves", "Acacia Bay", "Addington", "Adelaide", "Adventure", "Ahuriri", "Aidanfield", "Akatarawa", "Akina", "Alicetown", "Allen Road", "Allenton East", "Allenton West", "Amberley", "Anderson Park", "Aniseed Hill", "Aorangi", "Arakura", "Aranui", "Aro Street-Nairn Street", "Ascot Park", "Ashburton", "Ashburton Central East", "Ashburton Central West", "Ashburton East", "Ashburton North", "Atawhai", "Atmore", "Avalon East", "Avalon West", "Avon Loop", "Avondale", "Avonhead", "Avonhead West", "Avonside", "Awarua", "Awatoto", "Awhitu", "Bader", "Barrett", "Barrington North", "Barrington South", "Bay View", "Beckenham", "Beerescourt", "Belfast", "Belfast South", "Bell Block", "Bell Island", "Belmont", "Berhampore East", "Berhampore West", "Best Island", "Bexley", "Bishopdale", "Bishopdale North", "Blenheim", "Blenheim Central", "Bluff Hill", "Boulcott", "Bowden", "Brentwood", "Bridge Pa", "Brightwater", "Britannia", "Broads", "Bromley", "Bronte", "Brooklyn", "Brooklyn South", "Brookvale", "Broomfield", "Bryant", "Brymer", "Bryndwr", "Burbush", "Burnside", "Burwood", "Camberley", "Cambridge Central", "Cambridge North", "Cambridge West", "Cambridge Zone", "Camside", "Cannons Creek East", "Cannons Creek North", "Cannons Creek South", "Cape Rodney", "Cape Rodney South", "Carrington", "Casebrook", "Cashmere East", "Cashmere West", "Cathedral Square", "Chartwell", "Chedworth", "Christchurch", "Churton Park North", "Churton Park South", "Clarkin", "Clarkville", "Claudelands", "Clifton", "Clive", "Clouston Park", "Courtenay", "Crawshaw", "Crofton Downs", "Cromwell", "Dallington", "Darfield", "Deans Bush", "Delaney", "Diamond Harbour", "Dinsdale North", "Dinsdale South", "Discovery", "Eastbourne", "Ebdentown", "Edgeware", "Elderslea", "Elsdon-Takapuwahia", "Emerald Hill", "Endeavour", "Enderley", "Enner Glynn", "Ensors", "Epuni East", "Epuni West", "Eskdale", "Esplanade", "Eureka", "Fairton", "Fairview Downs", "Fendalton", "Fernlea", "Fernleigh", "Ferrymead", "Fitzroy", "Flagstaff", "Flaxmere East", "Frankleigh", "Frankton Junction", "Frimley", "Glen Avon", "Glendale", "Glenduan", "Glenside North", "Glenview", "Gordonton", "Governors Bay", "Gracefield", "Grampians", "Grandview", "Great Barrier Island", "Greenacres", "Greenmeadows", "Grenada North", "Grenada Village", "Hagley Park", "Halswell Domain", "Halswell South", "Halswell West", "Hamilton Central", "Hamilton East", "Hamilton Lake", "Hamilton Zone", "Hampstead", "Happy Valley-Owhiro Bay", "Harewood", "Hastings Central", "Hastings Zone", "Hataitai North", "Haumoana", "Hautapu", "Havelock Hills", "Havelock North Central", "Hawthornden", "Haywards-Manor Park", "Heathcote Valley", "Hendersons Basin", "Heretaunga", "Heretaunga-Silverstream", "Highfield Park", "Highlands Park", "Hikurangi", "Hillcrest West", "Hillmorton", "Hilltop", "Holborn", "Holmwood", "Homedale East", "Homedale West", "Hoon Hay", "Hoon Hay South", "Hope", "Horahora", "Hornby North", "Hornby South", "Horokiwi", "Horotiu", "Horsham Downs", "Hospital Hill", "Huntington", "Hutt Central", "Ilam", "Insoll", "Iona", "Irongate", "Isel Park", "Island Bay East", "Island Bay West", "Islands-Motutapu Rangitoto Rakino", "Islington", "Jackett Island", "Jellie Park", "Johnsonville Central", "Johnsonville East", "Johnsonville North", "Kaiapoi East", "Kaiapoi North East", "Kaiapoi North West", "Kaiapoi South", "Kaiapoi West", "Kaiaua", "Kainui", "Kaipaki", "Kaiwharawhara", "Kamo East", "Kamo West", "Kapiti", "Karaka Bay-Worser Bay", "Karamu", "Karori East", "Karori North", "Karori Park", "Karori South", "Katikati Community", "Kawakawa-Orere", "Kawaroa", "Kawau", "Kelburn", "Kelson", "Kennedys Bush", "Kensington", "Kerikeri", "Khandallah Park-Broadmeadows", "Kihikihi", "Kihikihi Flat", "Kilbirnie East", "Kilbirnie West-Hataitai South", "Kingsbury", "Kingsley-Chatham", "Kingston-Mornington", "Kirks", "Korokoro", "Lake Cameron", "Lake Ngaroto", "Lakewood", "Lambton", "Langbein", "Leamington East", "Leamington West", "Leeston", "Lehmans", "Leigh", "Lincoln", "Linden", "Linwood", "Linwood East", "Linwood North", "Little Barrier Island", "Lochain", "Longlands South", "Lower Hutt Zone", "Lyall Bay-Airport-Moa Point", "Lynmouth", "Lyttelton", "Maeroa", "Mahora", "Maidstone", "Mairehau", "Mairehau North", "Mairtown", "Maitai", "Maitlands", "Makara-Ohariu", "Mana-Camborne", "Mangaoraka", "Mangatawhiri", "Mangawhai", "Mangawhai Heads", "Mansfield", "Manuka", "Maoribank", "Mapua", "Maraenui", "Maramarua", "Marewa", "Marfell", "Marsland Hill", "Matakana", "Matamata", "Matamata North", "Matamata South", "Matangi", "Matheson Bay", "Maunganamu", "Maungaraki", "Maunu", "Maupuia", "Mayfair", "Mayfield", "Mclean Park", "Mcleans Island", "Meeanee", "Melling", "Melrose-Houghton Bay-Southgate", "Melville", "Meremere", "Merivale", "Merrilands", "Merrin", "Middleton", "Miramar", "Miramar North", "Miramar South", "Miramar West", "Mitchelltown", "Moera", "Mona Vale", "Moncks Bay", "Moonshine Valley", "Morningside", "Motueka", "Motueka East", "Motueka West", "Moturoa", "Mount Bryan", "Mt Cook-Wallace Street", "Mt Pleasant", "Mt Victoria West", "Naenae North", "Naenae South", "Napier Zone", "Nawton", "Nayland", "Naylor", "Nelson", "Nelson Airport", "Nelson Park", "Netherby", "New Brighton", "New Plymouth", "New Plymouth Central", "Newlands East", "Newlands North", "Newlands South", "Newstead", "Newtown East", "Newtown West", "Ngahinapouri", "Ngaio South", "Ngaruawahia", "Ngauranga East", "Ngauranga West", "Ngawhatu", "Ngunguru", "Normandale", "North Beach", "Northcote", "Northland", "Northland North", "Nukuhau", "Oaklands East", "Oaklands West", "Oakura", "Ohaupo", "Omaha", "Omahu", "Omaka", "Omata", "Onekawa Central", "Onekawa South", "Onekawa West", "Onepoto", "Onerahi", "Onewhero", "Opawa", "Oriental Bay", "Otaihanga", "Otaika-Portland", "Otangarei", "Otaua", "Other locations", "Oxford", "Paekakariki", "Pakipaki", "Pakowhai", "Papakowhai North", "Papakowhai South", "Papanui", "Paparangi", "Paparangi West", "Paparata", "Paparua", "Parahaki", "Paraite", "Parakai Rural", "Paraparaumu Beach North", "Paraparaumu Beach South", "Paraparaumu Central", "Paremata-Postgate", "Parklands", "Parkvale", "Parkway", "Pauatahanui", "Peachgrove", "Peacocke", "Peka Peka", "Petone Central", "Phillipstown", "Pinehaven", "Pines-Kairaki Beach", "Pirimai", "Plains Railway", "Plimmerton", "Poets Block", "Point Wells", "Poraiti", "Porirua Central", "Porirua East", "Porirua Zone", "Porritt", "Port Nelson", "Port-Limeburners", "Prebbleton", "Prestons", "Pukerimu", "Pukerua Bay", "Pukete", "Pukete West", "Quail Island", "Queenwood", "Raglan", "Rakaia", "Rangatira", "Rangatira Park", "Rangiora", "Rangiora Central", "Rangiora East", "Rangiora North", "Rangiora West", "Rangoon Heights", "Ranui Heights", "Ranzau", "Rapaki Track", "Rapaura", "Raroa", "Raumanga East", "Raumanga West", "Raumati Beach", "Raumati South", "Raureka", "Ravenswood", "Rawhiti", "Redwood North", "Redwood South", "Redwoodtown", "Regent", "Renwick", "Resolution", "Riccarton", "Riccarton South", "Riccarton West", "Richmond East", "Richmond Heights", "Richmond North", "Richmond South", "Richmond West", "Riverlands", "Riverlea", "Riverside", "Riverstone Terraces", "Rolleston", "Rolleston Central", "Rolleston North East", "Rolleston North West", "Rolleston South East", "Rolleston South West", "Roseneath", "Rotokauri", "Rototuna", "Russley", "Rutland", "Sawyers Arms", "Saxton", "Seatoun", "Seatoun Tunnel West", "Sherwood Rise", "Shirley East", "Shirley West", "Silverdale", "Silverstream", "Sockburn", "Somerfield", "South Brighton", "South Head", "Southbrook", "Spotswood", "Spreydon", "Spring Creek-Grovetown", "Springlands", "Springs Flat", "St Albans East", "St Albans West", "St Leonards", "St Martins", "Strathmore Park", "Strowan", "Struan Park", "Styx", "Styx Mill", "Sumner", "Swarbrick", "Swayne", "Sydenham", "Sylvester", "Tahuna Hills", "Tahunanui", "Taita North", "Taita South", "Taitville", "Takapu", "Tamahere-Tauwhare", "Tamatea North", "Tamatea South", "Taradale North", "Taradale South", "Tauhara", "Tauhoa-Puhoi", "Taupiri Community", "Taupo", "Taupo Central", "Taupo East", "Tawa Central", "Tawa South", "Tawhai", "Te Awamutu Central", "Te Awamutu East", "Te Awamutu South", "Te Awamutu West", "Te Awamutu Zone", "Te Hihi", "Te Kainga", "Te Kauwhata", "Te Kowhai", "Te Marua", "Te Mata", "Te Mata Hills", "Te Puke Community", "Te Puke East", "Te Puke West", "Te Rahu", "Te Rapa", "Te Rapa North", "Temple View", "Templeton", "The Brook", "The Wood", "Thorndon-Tinakori Road", "Three Mile Bush", "Tikipunga East", "Tikipunga West", "Tinwald", "Tirohanga", "Titahi Bay North", "Titahi Bay South", "Toi Toi", "Tokanui", "Totara Park", "Trafalgar", "Travis", "Travis Wetland", "Trentham North", "Trentham South", "Trents-Ladbrooks", "Twyford", "University", "Upper Hutt Central", "Upper Hutt Zone", "Upper Riccarton", "Upper Westown", "Vinetown", "Vogeltown", "Vogeltown West", "Wadestown", "Waihi Beach", "Waikanae Beach", "Waikanae East", "Waikanae Park", "Waikanae West", "Waimairi Beach", "Wainoni", "Waiohiki", "Waipahihi", "Wairakei-Aratiatia", "Wairarapa", "Waitangirua", "Waiwhetu North", "Waiwhetu South", "Wakefield", "Wallaceville", "Waltham", "Washington", "Waterloo East", "Waterloo West", "Welbourn", "Wellington Zone", "Wellsford", "Westburn", "Western Hills", "Westhaven", "Westmorland", "Westown", "Westshore", "Whakatu", "Whangamata", "Whangarei", "Whangarei Central", "Wharenui", "Wharewaka", "Whatawhata", "Whau Valley", "Whitianga", "Whitney", "Wigram", "Wilford", "Willis Street-Cambridge Terrace", "Wilton", "Witherlea", "Woburn North", "Woburn South", "Woodbourne", "Woodend", "Woodend", "Woodend West", "Woodhill", "Woodridge", "Woolston South", "Woolston West", "Woolwich", "Yaldhurst" };
	char area3[500][50] = { "Abbotsford", "Andersons Bay", "Aramoana", "Balmacewen", "Belleknowes", "Brighton", "Broad Bay-Portobello", "Brockville", "Bush Road", "Caledonian", "Caversham", "Company Bay", "Concord", "Corstorphine East", "Corstorphine West", "East Taieri", "Fairfield", "Fernhill", "Forbury", "Forrester Park", "Glenleith", "Green Island", "Halfway Bush", "Harbourside", "Helensburgh", "High St-Stuart St", "Inner Peninsula", "Kaikorai Hill", "Kenmure", "Macandrew Bay", "Maori Hill", "Mornington", "Mosgiel East", "Mosgiel South", "Musselburgh", "North Dunedin", "North East Valley", "Opoho", "Otago University", "Pine Hill", "Port Chalmers", "Ravensbourne", "Roslyn North", "Roslyn South", "Saddle Hill", "Sandymount", "Sawyers Bay", "South Dunedin", "St Clair", "St Kilda Central", "St Kilda East", "St Kilda West", "St Leonards-Blanket Bay", "Stuart St-Frederick St", "Taiaroa-Cape Saunders", "Vauxhall", "Wakari", "Waldronville", "Wingatui", "Woodhaugh", "Wyllies Crossing", "Feilding Central", "Feilding East", "Feilding North", "Feilding West", "Maewa", "Oroua Bridge", "Rakiraki", "Gisborne Airport", "Gisborne Central", "Kaiti North", "Kaiti South", "Makaraka", "Mangapapa", "Matokitoki", "Outer Kaiti", "Riverdale", "Tamarau", "Te Hapara", "Wainui", "Whataupoko", "Blaketown", "Cobden", "Greymouth Central", "Greymouth South", "Kaiata", "Karoro", "Runanga-Rapahoe", "South Beach-Camerons", "Hawera North", "Hawera South", "Hawera West", "Normanby", "Ohawe Beach", "Tawhiti", "Waingongoro", "Hokitika Urban", "Kaniere", "Huntly East", "Huntly West", "Kaitaia East", "Kaitaia West", "Kohitere", "Lake Horowhenua", "Levin East", "Levin North", "Levin South", "Levin West", "Playford Park", "Waiopehu", "Waitarere", "Homebush-Te Ore Ore", "Lansdowne", "Masterton Central", "Masterton East", "Masterton Railway", "Masterton West", "Ngaumutawa", "Opaki-Fernridge", "Solway North", "Solway South", "Morrinsville East", "Morrinsville West", "Ardgowan", "Cape Wanbrow", "Oamaru Central", "Oamaru North", "Oamaru South", "Orana Park", "Pukeuri", "Weston", "Aokautere", "Ashhurst", "Awapuni North", "Awapuni South", "Awapuni West", "Cloverlea", "Highbury", "Hokowhitu East", "Hokowhitu Lagoon", "Hokowhitu West", "Kairanga", "Kelvin Grove", "Linton Military Camp", "Longburn", "Massey University", "Milson", "Palmerston North Central", "Palmerston North Hospital", "Papaeoia", "Roslyn", "Stoney Creek", "Takaro", "Terrace End", "West End", "Westbrook", "Whakarongo", "Picton", "Waikawa", "Fairy Springs", "Fenton", "Fordlands", "Glenholme East", "Glenholme West", "Hillcrest", "Kawaha Point", "Koutu", "Kuirau", "Lynmore", "Mangakakahi", "Ngapuna", "Ngongotaha North", "Ngongotaha South", "Ohinemutu", "Owhata East", "Owhata South", "Owhata West", "Poets Corner", "Pomare", "Pukehangi North", "Pukehangi South", "Selwyn Heights", "Springfield", "Sunnybrook", "Utuhina", "Victoria", "Western Heights", "Whaka", "Moanataiari", "Parawai", "Fairview-Scarborough", "Fraser Park", "Gleniti", "Glenwood", "Highfield", "Maori Park", "Marchwiel", "Otipua Creek-Washdyke Flat", "Parkside", "Redruth", "Seaview", "Timaru Gardens", "Waimataitai", "Washdyke", "Watlington", "Waitara East", "Waitara West", "Allandale-Mokorua", "Coastlands", "Maraetotara", "Ohope", "Orini", "Poroporo", "Trident", "Whakatane North", "Whakatane West", "Alexandra", "Carterton", "Cloustonville", "Coromandel", "Dargaville", "Edgecumbe", "Geraldine", "Greytown", "Hanmer Springs", "Inglewood", "Kaikohe", "Kaikoura Township", "Kapiti Island", "Kauwhata", "Kawakawa", "Mana Island", "Mangaroa", "Martinborough", "Maungakotukutuku", "Methven", "Ngatea", "Opiki", "Otaki", "Otorohanga", "Paekakariki Hill", "Paeroa", "Paihia", "Pencarrow", "Pleasant Point", "Russell", "Shannon", "Taipa Bay-Mangonui", "Tairua", "Takaka", "Te Aroha", "Temuka", "Tokomaru", "Tokorangi-Hiwinui", "Twizel Community", "Waihi", "Waikouaiti", "Waipawa", "Winton" };
	char search[50];
	int len_search;
	output = 1;
	printf("Enter the suburb closest to you: ");
	while (output == 1) {
		gets_s(search);
		len_search = strlen(search);
		//Search area 1 for suburb
		for (i = 0; i < 500; i++) {
			for (j = 0; j < len_search; j++) {
				if ((isalpha(area1[i][j])) || (isalpha(search[j]))) {
					area1[i][j] = tolower(area1[i][j]);
					search[j] = tolower(search[j]);
				}
				if (area1[i][j] == search[j]) {
					if (j == len_search - 1) {
						return output;
					}
				}
				else if (area1[i][j] != search[j]) {
					break;
				}
			}
		}
		//Search area 2 for suburb
		output++;
		for (i = 0; i < 700; i++) {
			for (j = 0; j < len_search; j++) {
				if ((isalpha(area2[i][j])) || (isalpha(search[j]))) {
					area2[i][j] = tolower(area2[i][j]);
					search[j] = tolower(search[j]);
				}
				if (area2[i][j] == search[j]) {
					if (j == len_search - 1) {
						return output;
					}
				}
				else if (area2[i][j] != search[j]) {
					break;
				}
			}
		}
		//Search area 3 for suburb
		output++;
		for (i = 0; i < 500; i++) {
			for (j = 0; j < len_search; j++) {
				if ((isalpha(area3[i][j])) || (isalpha(search[j]))) {
					area3[i][j] = tolower(area3[i][j]);
					search[j] = tolower(search[j]);
				}
				if (area3[i][j] == search[j]) {
					if (j == len_search - 1) {
						return output;
					}
				}
				else if (area3[i][j] != search[j]) {
					break;
				}
			}
		}
		printf("Suburb \"%s\" was not found.\nPlease try the following:\n1. Don't use abbreviations.\n2. Enter your nearest town or city\n", search);
		output = 1;
	}
	return(0);
}

//Function to determine users living situation
int func_living_situation() {
	printf("Enter the living situation which best describes your circumstances:\n");
	for (i = 0; i < 5; i++) {
		printf("%d. ", i + 1);
		for (j = 0; j < 100; j++) {
			if (situation[i][j] != 0) {
				printf("%c", situation[i][j]);
			}
		}
		printf("\n");
	}
	scanf("%d", &output);
	getchar();
	return output;
}
//Function to search for users income threshold
int func_income_threshold(int area, int living_situation) {
	int cat[3][5] = {
		{449, 664, 702, 626, 262},
		{449, 664, 702, 626, 262},
		{449, 664, 702, 626, 626}
	};
	return cat[area - 1][living_situation - 1];
}
//Funtion to determine how much accommodation supplement is reduced by due to income
int func_reduction(int income, int income_threshold) {
	output = (income - income_threshold) * 0.25;
	if (output < 0) {
		output = 0;
	}
	return output;
}

//Determine accommodation costs
int func_acc_cost() {
	printf("Enter accommodation costs per week: $");
	scanf("%d", &output);
	getchar();
	return output;
}


//Function to determine users entry threshold
int func_entry_threshold(int living_situation) {
	int accomodation_type;
	printf("Do you:\n1. Rent or board\n2. Have a mortgage\n");
	scanf("%d", &accomodation_type);
	getchar();
	int entry_threshold[5][2] = {
		{63, 75},
		{100, 120},
		{135, 162},
		{122, 146},
		{122, 146}
	};
	output = entry_threshold[living_situation - 1][accomodation_type - 1];
	return output;
}

//Determine accommodation supplement before income reduction
int func_acc_supp(int living_situation, int area, int acc_cost, int entry_threshold) {
	int max[5][3] = {
		{165, 105, 80},
		{235, 155, 105},
		{305, 220, 160},
		{235,155, 105},
		{305, 220, 160}
	};
	printf("\nMaximum entitlement is: $%d", max[living_situation - 1][area - 1]);
	output = (acc_cost - entry_threshold) * 0.7;
	if (output > max[living_situation - 1][area - 1]) {
		output = max[living_situation - 1][area - 1];
	}
	return output;
}

//Determine accommodation supplement after income reduction
int func_acc_supp_final(int acc_supp, int reduction) {
	output = acc_supp - reduction;
	return output;
}