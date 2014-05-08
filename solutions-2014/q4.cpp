#include <vector>

#define MAXINT 2147000000

class DisjointSet {
public:
	DisjointSet(int size) {
		vector.assign(size, 0);
		for (int i = 0; i < size; ++i) {
			vector[i] = i;
		}
		sizes.assign(size, 1);
	}

	DisjointSet& join(int a, int b) {
		if (a == b) {
			return *this;
		}
		int indexA = find(a);
		int indexB = find(b);
		sizes[indexB] += sizes[indexA];
		vector[indexA] = vector[indexB];
		return *this;
	}

	int count() {
		int count = 0;
		for (int i = 0; i < (int) vector.size(); ++i) {
			if (vector[i] == i) {
				++count;
			}
		}
		return count;
	}

	int size(int set) {
		return sizes[find(set)];
	}

	bool isSameSet(int a, int b) {
		return find(a) == find(b);
	}

private:
	std::vector<int> vector;
	std::vector<int> sizes;

	int find(int set) {
		if (vector[set] == set) {
			return set;
		} else {
			vector[set] = find(vector[set]);
			return vector[set];
		}
	}
};

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>

struct Area {
	std::set<int> connections;
	int timeAsleep;
};

int main() {
	int sleepingAreas, connections;
	std::string line;
	std::cin >> sleepingAreas >> connections >> line;
	std::map<int, Area> areaMap;
	std::set<int> nodesToConnect;
	DisjointSet set(27);
	int maxSleep = 0;
	int representativeAwake = line[0] - 'A';
	for (unsigned int i = 0; i < line.length(); ++i) {
		Area area;
		area.timeAsleep = 0;
		areaMap[line[i] - 'A'] = area;
		set.join(line[i] - 'A', representativeAwake);
	}
	std::list<std::pair<int, int> > connectionsWaiting;
	while (connections--) {
		std::cin >> line;
		int first = line[0] - 'A';
		int second = line[1] - 'A';
		if (areaMap.count(first)) {
			areaMap[first].connections.insert(second);
		} else {
			Area area;
			area.timeAsleep = MAXINT;
			area.connections.insert(second);
			areaMap[first] = area;
			if (!set.isSameSet(representativeAwake, first))
				nodesToConnect.insert(first);
		}
		if (areaMap.count(second)) {
			areaMap[second].connections.insert(first);
		} else {
			Area area;
			area.timeAsleep = -1;
			area.connections.insert(first);
			areaMap[second] = area;
			if (!set.isSameSet(representativeAwake, second))
				nodesToConnect.insert(second);
		}
	}
	while (!nodesToConnect.empty()) {
		int connectedNodes = 0;
		std::set<int> connectThisTime;
		for (std::set<int>::iterator it = nodesToConnect.begin();
				it != nodesToConnect.end();) {
			int i = *it;
			Area& area = areaMap[*it];
			int countOn = 0, dist = -1;
			for (std::set<int>::iterator jt = area.connections.begin();
					jt != area.connections.end(); ++jt) {
				int j = *jt;
				if (set.isSameSet(*jt, representativeAwake)) {
					++countOn;
					dist = std::max(dist, areaMap[*jt].timeAsleep + 1);
				}
			}
			if (countOn >= 3) {
				area.timeAsleep = dist;
				maxSleep = std::max(maxSleep, dist);
				++connectedNodes;
//					set.join(*it, representativeAwake);
				connectThisTime.insert(*it);
				nodesToConnect.erase(it++);
			} else {
				it++;
			}
		}
		for (std::set<int>::iterator st = connectThisTime.begin(); st != connectThisTime.end(); ++st) {
			set.join(*st, representativeAwake);
		}
		connectThisTime.clear();
		if (!connectedNodes) {
			break;
		}
	}
	if (set.size(representativeAwake) == sleepingAreas) {
		std::cout << "Full infection will happen in " << maxSleep << " weeks."
			<< std::endl;
	} else {
		std::cout << "Full infection is not possible." << std::endl;
	}
}
