// Version 1. Work almost on all cases.
// Exceeded time on big input.
int poisonousPlants(vector<int> p) {

    vector<int> prevDay(p);
    vector<int> newDay(p.size());

    int daysPassedPrev = 1;
    int daysPassedCurr = 1;

    do {
        newDay.clear();

        daysPassedPrev = daysPassedCurr;
        bool wasDeleted = false;

        newDay.push_back(prevDay[0]);
        for (int i = 1; i < prevDay.size(); ++i) {
            if (prevDay[i - 1] < prevDay[i]) {
                wasDeleted = true;
            }
            else {
                newDay.push_back(prevDay[i]);
            }
        }

        if (wasDeleted) {
            daysPassedCurr++;
            prevDay = newDay;
        }
    } while (daysPassedCurr != daysPassedPrev);

    return daysPassedCurr - 1;
}
