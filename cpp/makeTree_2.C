#include <fstream>
#include <sstream>
#include <string>

#include "TFile.h"
#include "TTree.h"
#include "Event.h"

void makeTree_2()
{
    std::ifstream fin("data/dimuon_91_stable.txt");
    if (!fin.is_open()) {
        std::cout << "Cannot open input file\n";
        return;
    }

    TFile *fout = new TFile("data/dimuon_91.root","RECREATE");
    TTree *tree = new TTree("events","events");

    Event *evt = new Event();
    tree->Branch("event","Event",&evt);

    std::string line, tag;
    long iev;
    int idx, pdgID;
    double px, py, pz, ee, mm;
    bool isFirstEvent = true;

    while (std::getline(fin,line)) {
        if (line.empty()) continue;

        std::istringstream sstream(line);
        sstream >> tag;

        if (tag == "E:") {
            if (!isFirstEvent) tree->Fill();
            evt->clear();
            sstream >> iev;
            evt->setevt(iev);
            isFirstEvent = false;
        }
        else if (tag == "P:") {
            sstream >> idx >> pdgID >> px >> py >> pz >> ee >> mm;
            std::vector<double> p(3);
            p[0] = px; p[1] = py; p[2] = pz;
            Particle particle(pdgID, p, mm);
            evt->addParticle(particle);
        }
    }

    if (!isFirstEvent) tree->Fill();

    tree->Write();
    fout->Close();
    fin.close();

//    std::cout << "Done. Tree entries = " << tree->GetEntries() << std::endl;
}