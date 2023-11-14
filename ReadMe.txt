Task 2: Identifying Islands
Now that you've collected all the information you need, you're about to start working on the navigation feature of your app... when you make an important realisation! The population on Zephyrus is spread across contains several islands, some of which are fairly large. There is no way to drive between two islands, so if a user tries to find a route between two islands, you would like the app to respond quickly and tell the user that there is no route, instead of wasting time trying to find a route.

Therefore, you would like your app to pre-process the nodes and roads to identify islands. When a user wants to find a route between two nodes, the app will be able to check whether the two nodes are on the same island before calculating any routes.

Definition
Two nodes 
A
 and 
B
 are on the same island if and only if:

There is a road (either one-way or two-way) between 
A
 and 
B
, or
There is a road (either one-way or two-way) between 
A
 and a node which is on the same island as 
B
Consider the following road map (travel times are not shown as they are not relevant):


There are three islands on this map: one of them consists of the nodes 0, 3 and 5, another consists of the nodes 1, 4, 7 and 8, and the last island consists of the nodes 2 and 6. Note that 0 and 5 are on the same island, even though there is no route from 5 to 0.

In order to help achieve this, your task is to implement the following operations in the Road Map ADT. Note that you will need to modify some of your code from Task 1 to store information about islands (namely, your roadMap struct definition, RoadMapNew and RoadMapFree).

Operation	Signature/Description
RoadMapProcessIslands	
void RoadMapProcessIslands(RoadMap map);
Internally processes and saves information about islands based on the current roads in the map.
Assumes that no roads will be added to the map after this function is called.

Note: This function returns no value, so calling this function alone will have no observable effect from a user's perspective. However, the purpose of this operation is to compute and store information in the map to enable the following operations to be efficient. All operations below assume that this function has been called first.
RoadMapNumIslands	
int RoadMapNumIslands(RoadMap map);
Returns the number of islands.
Note: This function must have a worst-case time complexity of 
O
(
1
)
with respect to the number of nodes.
RoadMapOnSameIsland	
bool RoadMapOnSameIsland(RoadMap map, int node1, int node2);
Returns true if node1 and node2 are on the same island, and false otherwise.
Note: This function must have a worst-case time complexity of 
O
(
1
)
with respect to the number of nodes.
RoadMapSetIslandName	
void RoadMapSetIslandName(RoadMap map, int node, char *name);
Given a node, sets the name of the island that the node is on to the given name. If the island was already given a name, then it should be replaced with the given name.
Note: This function must have a worst-case time complexity of 
O
(
1
)
with respect to the number of nodes.
RoadMapGetIslandName	
char *RoadMapGetIslandName(RoadMap map, int node);
Given a node, returns the name of the island that the node is on, or "(unnamed)" if the island has not been named via RoadMapSetIslandName.
Note: This function must have a worst-case time complexity of 
O
(
1
)
with respect to the number of nodes.

Note: This function should simply return the island name stored in the map instead of a copy of the name. The user must not modify or free the returned string.
Example
Consider the following road map:


After this map is created, RoadMapProcessIslands will be called, which should process and store information about islands in the map. It can be assumed that no roads will be added to the map after RoadMapProcessIslands is called.

After RoadMapProcessIslands has been called, all the other island-related functions can now be called. For example:

RoadMapNumIslands should return 3, as there are three islands in the map.
RoadMapOnSameIsland(map, 0, 3) should return true, as nodes 0 and 3 are on the same island.
RoadMapOnSameIsland(map, 0, 5) should return true, as nodes 0 and 5 are on the same island.
RoadMapOnSameIsland(map, 5, 0) should return true, as nodes 5 and 0 are on the same island.
RoadMapOnSameIsland(map, 0, 1) should return false, as nodes 0 and 1 are not on the same island.
Suppose RoadMapSetIslandName(map, 0, "Bora Bora") is called. This should set the name of the island containing node 0 to "Bora Bora", which means if RoadMapGetIslandName is now called with the node 0, 3 or 5, it should return the string "Bora Bora".
