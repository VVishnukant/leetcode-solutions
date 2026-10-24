class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aStart = 0, aEnd = 0, bStart = 0, bEnd = 0;

        int aSM = stoi(arriveAlice.substr(0, 2));
        int aSD = stoi(arriveAlice.substr(3, 2));
        int aEM = stoi(leaveAlice.substr(0, 2));
        int aED = stoi(leaveAlice.substr(3, 2));

        int bSM = stoi(arriveBob.substr(0, 2));
        int bSD = stoi(arriveBob.substr(3, 2));
        int bEM = stoi(leaveBob.substr(0, 2));
        int bED = stoi(leaveBob.substr(3, 2));

        for (int i = 0; i < aSM - 1; i++){
            aStart += days[i];
        }
        aStart += aSD;

        for (int i = 0; i < aEM - 1; i++){
            aEnd += days[i];
        }
        aEnd += aED;

        for (int i = 0; i < bSM - 1; i++){
            bStart += days[i];
        }
        bStart += bSD;
        for (int i = 0; i < bEM - 1; i++){
            bEnd += days[i];
        }
        bEnd += bED;
        int count = 0;
        for (int day = aStart; day <= aEnd; day++) {
            if (day >= bStart && day <= bEnd) count++;
        }
        return count;
    }
};