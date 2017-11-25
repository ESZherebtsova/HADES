#include "TTree.h"
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include <TNtuple.h>
#include "TFile.h"
#include "TChain.h"
#include "TCanvas.h"

void Tracks() {

TChain *tree1=new TChain("tree");
tree1->Add("tree_1210823*.root");

TH1F *HMult1=new TH1F("Hmult1","",120,0,120);
TH1F *HMult2=new TH1F("Hmult2","",120,0,120);

Short_t nTracks;
tree1->SetBranchAddress("nTracks", &nTracks);
cout<<" tree1 start"<<endl;
int entry=0;
   while(entry < tree1->GetEntries()) {
                tree1->GetEntry(entry);
		HMult1->Fill(nTracks);
		entry++;

}
cout<<" tree 1 end"<<endl;
TFile *f1=new TFile("tree_12108235650.root","read");
TTree *t1=(TTree*)f1->Get("tree");


Short_t nTracks1;
t1->SetBranchAddress("nTracks", &nTracks1);

int entry1=0;
   while(entry1 < t1->GetEntries()) {
                t1->GetEntry(entry1);
                HMult2->Fill(nTracks1);
		entry1++;

}


TCanvas *c=new TCanvas("c");
c->cd();

HMult1->Draw();
HMult2->Draw("same");
HMult1->SetLineColor(4);
HMult2->SetLineColor(2);
}
