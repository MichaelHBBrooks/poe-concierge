# poe-concierge
Analyzes the stash and inventory of an account in Path of Exile.

# Development Notes
**This project is in an extremely alpha state.** It's likely not even functioning at this point.

To set expectations, the initial version 1.0.0 will allow a user to monitor specific tabs for items that would work with the chaos recipe. As in it will list the number of items for a given category (ie. gloves, helmets, rings, etc.) that meet the appropriate item level.

Later versions will analyze mods on items. This becomes complicated very quickly, so the easiest methods will be developed first. Some ideas include:

1. Unique item comparisons
   1. Find matching unique items, determine which is best.
   2. Find unique items and estimate worth based on rolls.
2. Simplistic user-defined rules for search hits.  
   For example, list all belts with 90+ life or 40+ energy shield and 80% elemental resistances.
3. Passive searches on items in inventory on trade sites. This will have to be slow so it doesn't overburden the trade API.  

There are a few more ideas that are far reaching. Getting these three done are somewhat attainable goals.
