#  Create a node containing the goal state node_goal
#  Create a node containing the start state node_start
#  Put node_start on the open list
#  while the OPEN list is not empty
#  {
#  Get the node off the open list with the lowest f and call it node_current
#  if node_current is the same state as node_goal we have found the solution; break from the while loop	    Generate each state node_successor that can come after node_current
#  for each node_successor of node_current
#      {
#          Set the cost of node_successor to be the cost of node_current plus the cost to get to node_successor from node_current
#          find node_successor on the OPEN list
#          if node_successor is on the OPEN list but the existing one is as good or better then discard this successor and continue
#          if node_successor is on the CLOSED list but the existing one is as good or better then discard this successor and continue
#          Remove occurences of node_successor from OPEN and CLOSED
#          Set the parent of node_successor to node_current
#          Set h to be the estimated distance to node_goal (Using the heuristic function)
#          Add node_successor to the OPEN list
#      }
#       Add node_current to the CLOSED list
#   }

#  If the OPEN list is empty then we have failed to find a solution
#  If we have found a solution then we have a path
#  Follow the path from node_goal to node_start
#  Print the path
#  Print the cost of the path
#  Print the number of nodes expanded
#  Print the number of states generated
#  Print the number of states on the OPEN list
#  Print the number of states on the CLOSED list

#A* algorithm Code: A_star.py

final_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]
start_state = [1, 2, 3, 8, 0, 4, 7, 6, 5]
unexpanded_states = []
expanded_states = []
closed_states = []
open_states = []
path = []
path_cost = 0
nodes_expanded = 0
states_generated = 0
states_on_open = 0
states_on_closed = 0



