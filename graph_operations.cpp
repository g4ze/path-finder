
#include <graphviz/gvc.h>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include "graph_operations.h"

// Define a structure to store location information
struct LocationInfo {
    std::string location;
    double distance;

    LocationInfo(const std::string& loc, double dist = 500.0) : location(loc), distance(dist) {}
};

// Define a graph as an adjacency list
class VillageMap {
public:
    VillageMap();
    void addLocation(const std::string& location);
    void addPath(const std::string& location1, const std::string& location2);
    void displayMap();
    
private:
    std::map<std::string, std::vector<LocationInfo>> mapGraph;
};

// Constructor: Initialize the village map
VillageMap::VillageMap() {
    mapGraph.clear();
}

// Add a location to the map
void VillageMap::addLocation(const std::string& location) {
    if (mapGraph.find(location) == mapGraph.end()) {
        mapGraph[location] = std::vector<LocationInfo>();
    }
}

// Add a path/connection between two locations with a default distance of 500 meters
void VillageMap::addPath(const std::string& location1, const std::string& location2) {
    mapGraph[location1].push_back(LocationInfo(location2));
    mapGraph[location2].push_back(LocationInfo(location1));
}

// Display the village map graphically using Graphviz
void VillageMap::displayMap() {
    // Create a new graph context
    Agraph_t* G = agopen("G", Agstrictdirected, nullptr);

    

    // Add nodes to the graph
    std::map<std::string, Agnode_t*> nodeMap;
    for (const auto& entry : mapGraph) {
        const std::string& location = entry.first;
        Agnode_t* node = agnode(G, (char*)location.c_str(), 1);
        nodeMap[location] = node;
    }

    // Add edges to the graph
    for (const auto& entry : mapGraph) {
        const std::string& location1 = entry.first;
        Agnode_t* node1 = nodeMap[location1];

        for (const LocationInfo& info : entry.second) {
            const std::string& location2 = info.location;
            Agedge_t* edge = agedge(G, node1, nodeMap[location2], nullptr, 1);
        }
    }

    // Initialize the Graphviz context
    GVC_t* gvc = gvContext();

    // Layout the graph
    gvLayout(gvc, G, "dot");

    // Render the graph to a file (e.g., PNG)
    gvRenderFilename(gvc, G, "png", "village_map.png");

    // Free resources
    gvFreeLayout(gvc, G);
    agclose(G);
    gvFreeContext(gvc);

    std::cout << "Graph visualization created successfully." << std::endl;
}

void loadGraph() {
    // Create a village map
    VillageMap village;

    // Add locations
   // Add locations
    village.addLocation("Noida City Centre");
    village.addLocation("Noida Golf Course");
    village.addLocation("Botanical Garden");
    village.addLocation("Noida Sector 18");
    village.addLocation("Noida Sector 16");
    village.addLocation("Noida Sector 15");
    village.addLocation("New Ashok Nagar");
    village.addLocation("Mayur Vihar Extension");
    village.addLocation("Mayur Vihar-I");
    village.addLocation("Akshardham");
    village.addLocation("Yamuna Bank");
    village.addLocation("Indraprastha");
    village.addLocation("Pragati Maidan");
    village.addLocation("Mandi House");
    village.addLocation("Barakhamba Road");
    village.addLocation("Rajiv Chowk");
    village.addLocation("R K Ashram Marg");
    village.addLocation("Jhandewalan");
    village.addLocation("Karol Bagh");
    village.addLocation("Rajendra Place");
    village.addLocation("Patel Nagar");
    village.addLocation("Shadipur");
    village.addLocation("Kirti Nagar");
    village.addLocation("Moti Nagar");
    village.addLocation("Ramesh Nagar");
    village.addLocation("Rajouri Garden");
    village.addLocation("Tagore Garden");
    village.addLocation("Subhash Nagar");
    village.addLocation("Janakpuri East");
    village.addLocation("Janakpuri West");
    village.addLocation("Uttam Nagar East");
    village.addLocation("Uttam Nagar West");
    village.addLocation("Nawada");
    village.addLocation("Dwarka Mor");
    village.addLocation("Dwarka");
    village.addLocation("Dwarka Sector 14");
    village.addLocation("Dwarka Sector 13");
    village.addLocation("Dwarka Sector 12");
    village.addLocation("Dwarka Sector 11");
    village.addLocation("Dwarka Sector 10");
    village.addLocation("Dwarka Sector 9");
    village.addLocation("Dwarka Sector 8");
    village.addLocation("Dwarka Sector 21");

    // Add paths between locations with a default distance of 500 meters
    // Chain-like connections
    village.addPath("Noida City Centre", "Noida Golf Course");
    village.addPath("Noida Golf Course", "Botanical Garden");
    village.addPath("Botanical Garden", "Noida Sector 18");
    village.addPath("Noida Sector 18", "Noida Sector 16");
    village.addPath("Noida Sector 16", "Noida Sector 15");
    village.addPath("Noida Sector 15", "New Ashok Nagar");
    village.addPath("New Ashok Nagar", "Mayur Vihar Extension");
    village.addPath("Mayur Vihar Extension", "Mayur Vihar-I");
    village.addPath("Mayur Vihar-I", "Akshardham");
    village.addPath("Akshardham", "Yamuna Bank");
    village.addPath("Yamuna Bank", "Indraprastha");
    village.addPath("Indraprastha", "Pragati Maidan");
    village.addPath("Pragati Maidan", "Mandi House");
    village.addPath("Mandi House", "Barakhamba Road");
    village.addPath("Barakhamba Road", "Rajiv Chowk");
    village.addPath("Rajiv Chowk", "R K Ashram Marg");
    village.addPath("R K Ashram Marg", "Jhandewalan");
    village.addPath("Jhandewalan", "Karol Bagh");
    village.addPath("Karol Bagh", "Rajendra Place");
    village.addPath("Rajendra Place", "Patel Nagar");
    village.addPath("Patel Nagar", "Shadipur");
    village.addPath("Shadipur", "Kirti Nagar");
    village.addPath("Kirti Nagar", "Moti Nagar");
    village.addPath("Moti Nagar", "Ramesh Nagar");
    village.addPath("Ramesh Nagar", "Rajouri Garden");
    village.addPath("Rajouri Garden", "Tagore Garden");
    village.addPath("Tagore Garden", "Subhash Nagar");
    village.addPath("Subhash Nagar", "Janakpuri East");
    village.addPath("Janakpuri East", "Janakpuri West");
    village.addPath("Janakpuri West", "Uttam Nagar East");
    village.addPath("Uttam Nagar East", "Uttam Nagar West");
    village.addPath("Uttam Nagar West", "Nawada");
    village.addPath("Nawada", "Dwarka Mor");
    village.addPath("Dwarka Mor", "Dwarka");
    village.addPath("Dwarka", "Dwarka Sector 14");
    village.addPath("Dwarka Sector 14", "Dwarka Sector 13");
    village.addPath("Dwarka Sector 13", "Dwarka Sector 12");
    village.addPath("Dwarka Sector 12", "Dwarka Sector 11");
    village.addPath("Dwarka Sector 11", "Dwarka Sector 10");
    village.addPath("Dwarka Sector 10", "Dwarka Sector 9");
    village.addPath("Dwarka Sector 9", "Dwarka Sector 8");
    village.addPath("Dwarka Sector 8", "Dwarka Sector 21");
    
    // Connections to Yamuna Bank
    village.addPath("Yamuna Bank", "Laxmi Nagar");
    village.addPath("Laxmi Nagar", "Nirman Vihar");
    village.addPath("Nirman Vihar", "Preet Vihar");
    village.addPath("Preet Vihar", "Karkarduma");
    village.addPath("Karkarduma", "Anand Vihar ISBT");
    village.addPath("Anand Vihar ISBT", "Kaushambi");
    village.addPath("Kaushambi", "Vaishali");
    
    // Connections to Kirti Nagar
    village.addPath("Kirti Nagar", "Satguru Ramsingh Marg");
    village.addPath("Satguru Ramsingh Marg", "Ashok Park Main");
    village.addPath("Ashok Park Main", "Punjabi Bagh East");
    village.addPath("Punjabi Bagh East", "Shivaji Park");
    village.addPath("Shivaji Park", "Madipur");
    village.addPath("Madipur", "Paschim Vihar East");
    village.addPath("Paschim Vihar East", "Paschim Vihar West");
    village.addPath("Paschim Vihar West", "Peera Garhi");
    village.addPath("Peera Garhi", "Udyog Nagar");
    village.addPath("Udyog Nagar", "Surajmal Stadium");
    village.addPath("Surajmal Stadium", "Nangloi");
    village.addPath("Nangloi", "Nangloi Railway station");
    village.addPath("Nangloi Railway station", "Rajdhani Park");
    village.addPath("Rajdhani Park", "Mundka");

    // Display the village map graphically
    village.displayMap();

    std::cout << "Graph loaded successfully." << std::endl;
}
