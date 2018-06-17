#include <iostream>
#include <algorithm>
#include <vector>
#include "altruistmerchant.h"
#include "roguemerchant.h"
#include "dodgermerchant.h"
#include "unpredictablemerchant.h"
#include "rancorousmerchant.h"
#include "quirkymerchant.h"
#include "randomgenerator.h"
#include "transaction.h"
using namespace std;


static bool cmp(IMerchant* const l, IMerchant* const r){
    return l->getTotalProfit() > r->getTotalProfit();
}

int main()
{
    std::vector<IMerchant*> merchants;
    merchants.reserve(60);
    for (int i = 0; i < 6; i++){
        IMerchant* m = nullptr;
        switch (i) {
        case 0:
            m = new AltruistMerchant();
            break;
        case 1:
            m = new RogueMerchant();
            break;
        case 2:
            m = new DodgerMerchant();
            break;
        case 3:
            m = new UnpredictableMerchant();
            break;
        case 4:
            m = new RancorousMerchant();
            break;
        case 5:
            m = new QuirkyMerchant();
            break;

        default:
            return -1;
        }
        merchants.push_back(m);
        for (int  j = 0; j < 9; j++){
            merchants.push_back(m->createNewMerchant());
        }
    }
    std::vector< std::pair<int, int> > pairs;
    for (int i = 0; i < 60; i++){
        for (int j = i; j < 60; j++){
            pairs.push_back({i,j});
        }
    }
    int YearsCount = 0;
    cout << "Enter count of years for modeling" << std::endl;
    cin >> YearsCount;
    for (int year = 0; year < YearsCount; year++){
        int transactionPerYearCount = randomgen::getCountTransactionsPerYear();
        for (int i = 0; i < transactionPerYearCount; i++){
            randomgen::shuffle(pairs);
            for (const auto& p: pairs){
                doTransaction(merchants[p.first], merchants[p.second]);
            }
        }
        if (year != YearsCount - 1){
            std::sort(merchants.begin(), merchants.end(), cmp);
            for (int i = 0; i < 12; i++){
                delete merchants[59-i];
                merchants[59-i] = merchants[i]->createNewMerchant();
            }
            for (auto& m: merchants){
                m->reset();
            }
        }
    }
    std::sort(merchants.begin(), merchants.end(), cmp);
    for (const auto& m: merchants){
        std::cout << m->getDescription() << std::endl;
    }
    for (auto& m: merchants){
        delete m;
    }
    return 0;
}

