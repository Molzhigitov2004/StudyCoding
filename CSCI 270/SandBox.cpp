#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int Partition(std::vector<int>& array, int low, int high){
    int pivot = array[low];
    int i = low;
    int j = high;
    while(i < j){
        do{
            i++;
        }while(array[i] < pivot && i < high);
        do{
            j--;
        }while(array[j] > pivot && j > low);
        if(i < j){
        std::swap(array[i], array[j]);
        }
    }
    std::swap(array[low], array[j]);
    return j;
}

void QuickSort(std::vector<int>& array, int low, int high){
    if(low < high){
        int pivot = Partition(array, low, high);
        QuickSort(array, low, pivot-1);
        QuickSort(array, pivot+1, high);
    }
}

void printClusters(const map<int, vector<int>>& clusters) {
    for (const auto& cluster : clusters) {  
        int centroid = cluster.first;
        const vector<int>& points = cluster.second;

        cout << "Centroid " << centroid << ": ";
        for (int point : points) {
            cout << point << " ";
        }
        cout << endl;
    }
} //Used for debugging

void selectCentroids(int min, int max, int amount, set<int>& centroids){
    while(centroids.size() < amount){
        centroids.insert(min + rand() % (max - min + 1));
    }
}//This function will return initially selected random centroids

void assignToClusters(const vector<int>& locations, const set<int>& centroids, map<int, vector<int>>& clusters) {
    for (int centroid : centroids) {
        clusters[centroid] = {};
    }
    for (int point : locations) {
        int bestCentroid = *centroids.begin();
        int minDist = abs(point - bestCentroid);
        
        for (int centroid : centroids) {
            int dist = abs(point - centroid);
            if (dist < minDist) {
                bestCentroid = centroid;
                minDist = dist;
            }
        }
        
        clusters[bestCentroid].push_back(point);
    }
}//create map for cluster where centroid is key
int getMedian(vector<int>& cluster){
    QuickSort(cluster, 0, cluster.size()-1);
    return (cluster[0] + cluster[cluster.size()-1])/2;
}//helper function that will get new Centroids using Median

void calibrateCentroids(const vector<int>& locations,set<int>& centroids, map<int, vector<int>>& clusters) {
    set<int> newCentroids;
    while (true) {
        newCentroids.clear();

        for (const auto& cluster : clusters) {
            if (!cluster.second.empty()) {
                vector<int> clusterCopy = cluster.second;
                int newCentroid = getMedian(clusterCopy);
                newCentroids.insert(newCentroid);
            } else {
                newCentroids.insert(cluster.first);
            }
        }
        if (centroids == newCentroids) {
            break;
        }
        centroids = newCentroids;
        clusters.clear();
        assignToClusters(locations, centroids, clusters);
    }
}

int getTotalVariance(const map<int, vector<int>>& clusters) {
    int totalVariance = 0;

    for (const auto& cluster : clusters) {
        int centroid = cluster.first;
        for (int point : cluster.second) {
            int diff = point - centroid;
            totalVariance += diff * diff;
        }
    }

    return totalVariance;
}


int getMaximumDistance(vector<int> location, int k) {
    std::srand(std::time(0));
    if (location.empty() || k <= 0) return -1; // This is edge case
    int maxVal = INT_MIN; //This bloke searches for MAX and MIN to generate random centroids
    int minVal = INT_MAX;
    for(int i = 0; i < location.size(); i++){
      if(maxVal < location[i]) maxVal = location[i];
      if(minVal > location[i]) minVal = location[i];
    }
    set<int> finalCentroids;
    int minVariance = INT_MAX;
    for(int i = 0; i < 300; i++){
        set<int> centroids;
        selectCentroids(minVal, maxVal, k, centroids);
        map<int, vector<int>> clusters;
        assignToClusters(location, centroids, clusters);

        calibrateCentroids(location, centroids, clusters);

        int currentVariance = getTotalVariance(clusters);
        if(currentVariance < minVariance){
            finalCentroids = centroids;
            minVariance = currentVariance;
        }    
    }
    
    
    map<int, vector<int>> finalClusters;
    assignToClusters(location, finalCentroids, finalClusters);
    int maxDistance = INT_MIN;
    for(const auto& cluster : finalClusters){
        for(const int location : cluster.second){
            int currentDistance = abs(cluster.first - location);
            if(currentDistance > maxDistance) maxDistance = currentDistance; 
        }
    }
    
    return maxDistance;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string location_count_temp;
    getline(cin, location_count_temp);

    int location_count = stoi(ltrim(rtrim(location_count_temp)));

    vector<int> location(location_count);

    for (int i = 0; i < location_count; i++) {
        string location_item_temp;
        getline(cin, location_item_temp);

        int location_item = stoi(ltrim(rtrim(location_item_temp)));

        location[i] = location_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = getMaximumDistance(location, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
