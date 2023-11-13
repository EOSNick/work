#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "RoadMap.h"
#include "time.h"

typedef struct Node {
    // Define the structure of a node
	int id;
	struct road* roadsFrom[MAX_ROADS_PER_NODE];
	struct road* roadsTo[MAX_ROADS_PER_NODE];
	int numRoadsFrom;
	int numRoadsTo;
	int numRoads;
} Node;

struct roadMap {
	// TODO
	Node* nodes;
	struct road* roads;
	int numNodes;
	int numRoads;
	int numTwoWay;
};

////////////////////////////////////////////////////////////////////////
// Task 1

RoadMap RoadMapNew(int numNodes) {
    // TODO
    struct roadMap* newMap = (struct roadMap*)malloc(sizeof(struct roadMap));
    if(newMap == NULL) {
        return NULL;
    }
    newMap->nodes = (Node*)malloc(numNodes * sizeof(Node));
    if(newMap->nodes == NULL) {
        free(newMap);
        return NULL;
    }
    newMap->numNodes = numNodes;
    newMap->roads = NULL;  // Initialize roads to NULL
    newMap->numRoads = 0;

    for(int i = 0; i < numNodes; i++) {
        newMap->nodes[i].numRoadsFrom = 0;
        newMap->nodes[i].numRoadsTo = 0;
        newMap->nodes[i].numRoads = 0;
        for(int j = 0; j < MAX_ROADS_PER_NODE; j++) {
            newMap->nodes[i].roadsFrom[j] = NULL; 
            newMap->nodes[i].roadsTo[j] = NULL;    
        }
    }
    return newMap;
}


void RoadMapFree(RoadMap map) {
	if(map != NULL) {
		free(map->nodes);
		free(map->roads);
		free(map);
	}
}

int RoadMapNumNodes(RoadMap map) {
	// TODO
	if(map->nodes == NULL) {
		return 0;
	}
	return map->numNodes;

}

int RoadMapNumRoads(RoadMap map) {
	// TODO
	if(map->nodes == NULL) {
		return 0;
	}
	return map->numRoads;
}

bool RoadMapAddRoad(RoadMap map, int node1, int node2,
                    bool isTwoWay, int travelMinutes) {
    // TODO
    // Checks if the map exists and the nodes exist
    if (map == NULL || node1 < 0 || node1 >= map->numNodes || node2 < 0 || node2 >= map->numNodes) {
        return false;
    }

    // Checks if either nodes have the max amount of roads allocated already
    if (map->nodes[node1].numRoads >= MAX_ROADS_PER_NODE || map->nodes[node2].numRoads >= MAX_ROADS_PER_NODE) {
        return false;
    }

    if (map->roads == NULL) {
        map->roads = (struct road*)malloc(MAX_ROADS_PER_NODE * map->numNodes * sizeof(struct road));
    } else {
        // Checks if there is already a road between the two nodes
        for (int i = 0; i < map->numRoads; i++) {
            if (map->roads[i].fromNode == node1 && map->roads[i].toNode == node2) {
                return false;
            }
            if (map->roads[i].fromNode == node2 && map->roads[i].toNode == node1) {
                return false;
            }
        }
    }
	/*
	if(isTwoWay && node1 > node2) {
		int temp = node1;
		node1 = node2;
		node2 = temp;
	}*/
    // Adds the road from node1 to node2
    struct road* road = &map->roads[map->numRoads];
    road->fromNode = node1;
    road->toNode = node2;
    road->travelMinutes = travelMinutes;

    map->nodes[node1].roadsFrom[map->nodes[node1].numRoadsFrom] = road;
    map->nodes[node1].numRoadsFrom++;

    map->nodes[node2].roadsTo[map->nodes[node2].numRoadsTo] = road;
    map->nodes[node2].numRoadsTo++;
	

    // TODO: Add the road from node2 to node1 if it is a two-way road
    if (isTwoWay == true) {
        struct road* returnRoad = &map->roads[map->numRoads];
        returnRoad->fromNode = node1;
        returnRoad->toNode = node2;
        returnRoad->travelMinutes = travelMinutes;

		map->nodes[node2].roadsFrom[map->nodes[node2].numRoadsFrom] = returnRoad;
    	map->nodes[node2].numRoadsFrom++;

		map->nodes[node1].roadsTo[map->nodes[node1].numRoadsTo] = returnRoad;
        map->nodes[node1].numRoadsTo++;

    }
	map->nodes[node1].numRoads++;
	map->nodes[node2].numRoads++;
    map->numRoads++;
    return true;
}


int RoadMapGetRoadsFrom(RoadMap map, int node, struct road roads[]) {
	for(int i = 0; i < map->nodes[node].numRoadsFrom; i++) {
		roads[i] = *map->nodes[node].roadsFrom[i];
	}
	return map->nodes[node].numRoadsFrom;
}

int RoadMapGetRoadsTo(RoadMap map, int node, struct road roads[]) {
    // TODO
    for (int i = 0; i < map->nodes[node].numRoadsTo; i++) {
        roads[i] = *map->nodes[node].roadsTo[i];
        printf("from Node %d \t", roads[i].fromNode);
        printf("to Node %d\n", roads[i].toNode);
    }
    return map->nodes[node].numRoadsTo;
}


////////////////////////////////////////////////////////////////////////
// Task 2

void RoadMapProcessIslands(RoadMap map) {
	// TODO
}

int RoadMapNumIslands(RoadMap map) {
	// TODO
	return 0;
}

bool RoadMapOnSameIsland(RoadMap map, int node1, int node2) {
	// TODO
	return 0;
}

void RoadMapSetIslandName(RoadMap map, int node, char *name) {
	// TODO
}

char *RoadMapGetIslandName(RoadMap map, int node) {
	// TODO
	return "(unnamed)";
}

////////////////////////////////////////////////////////////////////////
// Task 3

void RoadMapAddTrafficLights(RoadMap map, int node) {
	// TODO
}

bool RoadMapHasTrafficLights(RoadMap map, int node) {
	// TODO
	return false;
}

////////////////////////////////////////////////////////////////////////
// Task 4

void RoadMapSetClosedTimes(RoadMap map, int node1, int node2,
                           struct time from, struct time until) {
	// TODO
}

