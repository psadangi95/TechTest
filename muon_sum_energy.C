#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "cpp/Event.h"
#include <cmath>

void muon_sum_energy()
{
    TFile *f = TFile::Open("data/dimuon_91.root");
    TTree *t = (TTree*)f->Get("events");

    Event *evt = 0;
    t->SetBranchAddress("event", &evt);

    TH1D *h = new TH1D("h"," ;#Sigma E_{#mu};Events",100, 70, 100);

    for (int i = 0; i < t->GetEntries(); i++) {
        t->GetEntry(i);
        double sumMuonE = 0.0;

        for (size_t j = 0; j < evt->particles.size(); j++)
        {
            if (std::abs(evt->particles[j].typ) == 13) 
                sumMuonE = sumMuonE + evt->particles[j].ee;
        }

        h->Fill(sumMuonE);
    }

    TCanvas *c = new TCanvas("c","c",700,600);
    h->Draw();
    c->SaveAs("muon_sum_energy.png");
    f->Close();
}