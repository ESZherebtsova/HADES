#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TColor.h>
#include <TH1F.h>
#include <TH2F.h>
#include <iostream>
#include <MHConstants.h>

void drawCommonHists(char* input="/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_14_11_56", char* outputdir="/lustre/nyx/cbm/users/ogolosov/HADES/treeMaker/output/Nov_14_11_56") {
    TChain* ch = new TChain();
    char trees[200];
    char picName[200];
    char cutEq0[] = "wallQw[0]*wallQw[1]*wallQw[2]*wallQw[3]*wallQw[4]*wallQw[5]*wallQwRandom[0]*wallQwRandom[1]*wallQwRandom[2]*wallQwRandom[3]*wallQwRandom[4]*wallQwRandom[5]*wallQwRandom[6]*wallQwRandom[7]*wallQwRandom[8]*wallQwRandom[9]*mdcQw[0]*mdcQw[1]*mdcQw[2]==0";    
    char cutNEq0[] = "wallQw[0]*wallQw[1]*wallQw[2]*wallQw[3]*wallQw[4]*wallQw[5]*wallQwRandom[0]*wallQwRandom[1]*wallQwRandom[2]*wallQwRandom[3]*wallQwRandom[4]*wallQwRandom[5]*wallQwRandom[6]*wallQwRandom[7]*wallQwRandom[8]*wallQwRandom[9]*mdcQw[0]*mdcQw[1]*mdcQw[2]!=0";    
    sprintf(trees, "%s/tree_1210816*.root/tree", input);
    ch->Add(trees);
    long n = 50000000;
    long n1 = 3000000;
    double zMax = 3e-3*(double)n1;
    TCanvas* canv;
    TLegend* leg;
    char str1[100];
    char str2[100];
    char subName1[30];
    char subName2[30];

    TH2F* fwVsMultBefore = new TH2F("fwVsMultBefore", "Qw(FW) Vs NTracks before event cut;NTracks;Qw(FW)", 120, 0, 120, 70, 0, 70); 
    TH2F* fwVsMultAccepted = new TH2F("fwVsMultAccepted", "Qw(FW) Vs NTracks after event cut;NTracks;Qw(FW)", 120, 0, 120, 70, 0, 70); 
    TH2F* fwVsMultCut = new TH2F("fwVsMultCut", "Qw(FW) Vs NTracks: cut events;NTracks;Qw(FW)", 120, 0, 120, 70, 0, 70); 
    TH2F* ring7_9VsMultBefore = new TH2F("ring7_9VsMultBefore", "Qw(ring7_9) Vs NTracks before event cut;NTracks;Qw(ring7_9)", 120, 0, 120, 50, 0, 50); 
    TH2F* ring7_9VsMultAccepted = new TH2F("ring7_9VsMultAccepted", "Qw(ring7_9) Vs NTracks after event cut;NTracks;Qw(ring7_9)", 120, 0, 120, 50, 0, 50); 
    TH2F* ring7_9VsMultCut = new TH2F("ring7_9VsMultCut", "Qw(ring7_9) Vs NTracks: cut events;NTracks;Qw(ring7_9)", 120, 0, 120, 50, 0, 50); 
    TH2F* ring1_6VsMultBefore = new TH2F("ring1_6VsMultBefore", "Qw(ring1_6) Vs NTracks before event cut;NTracks;Qw(ring1_6)", 120, 0, 120, 50, 0, 50); 
    TH2F* ring1_6VsMultAccepted = new TH2F("ring1_6VsMultAccepted", "Qw(ring1_6) Vs NTracks after event cut;NTracks;Qw(ring1_6)", 120, 0, 120, 50, 0, 50); 
    TH2F* ring1_6VsMultCut = new TH2F("ring1_6VsMultCut", "Qw(ring1_6) Vs NTracks: cut events;NTracks;Qw(ring1_6)", 120, 0, 120, 50, 0, 50); 

   TH2F* ring1_6VsMultCut_Ch = new TH2F("ring1_6VsMultCut", "Qw(ring1_6) Vs NTracks: cut events;NTracks;Q FW(ring1_6)", 120, 0, 120, 150, 0, 15000);
TH2F* ring7_9VsMultCut_Ch = new TH2F("ring7_9VsMultCut", "Qw(ring7_9) Vs NTracks: cut events;NTracks;Q FW(ring7_9)", 120, 0, 120, 150, 0, 15000);
TH2F* ring1VsMultCut_Ch = new TH2F("ring1VsMultCut", "Qw(ring1) Vs NTracks: cut events;NTracks;Q FW(ring1)", 120, 0, 120, 150, 0, 15000);
TH2F* ring2VsMultCut_Ch = new TH2F("ring2VsMultCut", "Qw(ring2) Vs NTracks: cut events;NTracks;Q FW(ring2)", 120, 0, 120, 150, 0, 15000);
TH2F* ring3VsMultCut_Ch = new TH2F("ring3VsMultCut", "Qw(ring3) Vs NTracks: cut events;NTracks;Q FW(ring3)", 120, 0, 120, 150, 0, 15000);
TH2F* ring4VsMultCut_Ch = new TH2F("ring4VsMultCut", "Qw(ring4) Vs NTracks: cut events;NTracks;Q FW(ring4)", 120, 0, 120, 150, 0, 15000);
TH2F* ring5VsMultCut_Ch = new TH2F("ring5VsMultCut", "Qw(ring5) Vs NTracks: cut events;NTracks;Q FW(ring5)", 120, 0, 120, 150, 0, 15000);
TH2F* ring6VsMultCut_Ch = new TH2F("ring6VsMultCut", "Qw(ring6) Vs NTracks: cut events;NTracks;Q FW(ring6)", 120, 0, 120, 150, 0, 15000);
TH2F* ring7VsMultCut_Ch = new TH2F("ring7VsMultCut", "Qw(ring7) Vs NTracks: cut events;NTracks;Q FW(ring7)", 120, 0, 120, 150, 0, 15000);
TH2F* ring8VsMultCut_Ch = new TH2F("ring8VsMultCut", "Qw(ring8) Vs NTracks: cut events;NTracks;Q FW(ring8)", 120, 0, 120, 150, 0, 15000);
TH2F* ring9VsMultCut_Ch = new TH2F("ring9VsMultCut", "Qw(ring9) Vs NTracks: cut events;NTracks;Q FW(ring9)", 120, 0, 120, 150, 0, 15000);

    TH1F* hNTracksBefore = new TH1F("hNTracksBefore", "Multiplicity distribution; NTracks",120,0,120);
    TH1F* hNTracksAccepted = new TH1F("hNTracksAccepted", "Multiplicity distribution; NTracks",120,0,120);
    TH1F* hNTracksCut = new TH1F("hNTracksCut", "Multiplicity distribution; NTracks",120,0,120);

    TH2F* hRandomQwAVsQwB[5];
    for (int i=eWallRandomA, j=0; i<=eWallRing1_6RandomA; i+=2, j++) {
        GetSubEventTag(i,subName1);
        sprintf(str1, "hRandomQwAVsQwB%s", subName1);
        GetSubEventName(i, subName1);
        GetSubEventName(i+1, subName2);
        sprintf(str2, "Qw_{%s} vs Qw_{%s};Qw_{%s};Qw_{%s}", subName1, subName2, subName1, subName2);
        hRandomQwAVsQwB[j] = new TH2F(str1, str2, 40,0,40,40,0,40);
    }
    ch->Draw("wallChargeTot_ring16:nTracks>>ring1_6VsMultCut_Ch(120,0,120,150,0,15000","","colz");
    ch->Draw("wallChargeTot_ring79:nTracks>>ring7_9VsMultCut_Ch","","colz",n);

    ch->Draw("wallQw[0]:nTracks>>fwVsMultBefore", "", "colz", n);
    ch->Draw("wallQw[0]:nTracks>>fwVsMultAccepted", cutNEq0, "colz", n);
    ch->Draw("wallQw[0]:nTracks>>fwVsMultCut", cutEq0, "colz", n);
    ch->Draw("wallQw[1]:nTracks>>ring7_9VsMultBefore", "", "colz", n);
    ch->Draw("wallQw[1]:nTracks>>ring7_9VsMultAccepted", cutNEq0, "colz", n);
    ch->Draw("wallQw[1]:nTracks>>ring7_9VsMultCut", cutEq0, "colz", n);
    ch->Draw("wallQw[2]:nTracks>>ring1_6VsMultBefore", "", "colz", n);
    ch->Draw("wallQw[2]:nTracks>>ring1_6VsMultAccepted", cutNEq0, "colz", n);
    ch->Draw("wallQw[2]:nTracks>>ring1_6VsMultCut", cutEq0, "colz", n);
    ch->Draw("nTracks>>hNTracksBefore", "", "", n);
    ch->Draw("nTracks>>hNTracksAccepted", cutNEq0, "", n);
    ch->Draw("nTracks>>hNTracksCut", cutEq0, "", n);
    for (int i=eWallRandomA, j=0; i<=eWallRing1_6RandomA; i+=2, j+=2) {
        GetSubEventTag(i, subName1);
        sprintf(str1,"wallQwRandom[%i]:wallQwRandom[%i]>>hRandomQwAVsQwB%s", j+1, j, subName1);
        ch->Draw(str1, cutNEq0, "colz", n);
    }
    TFile* TreeFile = new TFile("Hist.root","RECREATE");

		 TTree* myTree  = new TTree("tree","tree");
tree->Fill();
TreeFile->cd();

	tree ->Write();



canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring1_6VsMultCut_Ch->Draw("colz");
    ring1_6VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring1_6VsMultCut_Ch->SetStats(false);
ring1_6VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring1_6VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring1_6VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;


canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring7_9VsMultCut_Ch->Draw("colz");
    ring7_9VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring7_9VsMultCut_Ch->SetStats(false);
ring7_9VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring7_9VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring7_9VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring1VsMultCut_Ch->Draw("colz");
    ring1VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring1VsMultCut_Ch->SetStats(false);
ring1VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring1VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring1VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring2VsMultCut_Ch->Draw("colz");
    ring2VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring2VsMultCut_Ch->SetStats(false);
ring2VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring2VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring2VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring3VsMultCut_Ch->Draw("colz");
    ring3VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring3VsMultCut_Ch->SetStats(false);
ring3VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring3VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring3VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring4VsMultCut_Ch->Draw("colz");
    ring4VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring4VsMultCut_Ch->SetStats(false);
ring4VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring4VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring4VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring5VsMultCut_Ch->Draw("colz");
    ring5VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring5VsMultCut_Ch->SetStats(false);
ring5VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring5VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring5VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring6VsMultCut_Ch->Draw("colz");
    ring6VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring6VsMultCut_Ch->SetStats(false);
ring6VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring6VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring6VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring7VsMultCut_Ch->Draw("colz");
    ring7VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring7VsMultCut_Ch->SetStats(false);
ring7VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring7VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring7VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring8VsMultCut_Ch->Draw("colz");
    ring8VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring8VsMultCut_Ch->SetStats(false);
ring8VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring8VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring8VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;

canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring9VsMultCut_Ch->Draw("colz");
    ring9VsMultCut_Ch->GetZaxis()->SetRangeUser(0,zMax);
    ring9VsMultCut_Ch->SetStats(false);
ring9VsMultCut_Ch->Write();
    sprintf(picName, "%s/pics/ring9VsMultCut_Ch.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring9VsMultCut_Ch.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;









    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    fwVsMultBefore->Draw("colz");
    fwVsMultBefore->GetZaxis()->SetRangeUser(0,zMax);
    fwVsMultBefore->SetStats(false);
fwVsMultBefore->Write();
    sprintf(picName, "%s/pics/fwBefore.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/fwBefore.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    fwVsMultAccepted->Draw("colz");
    fwVsMultAccepted->GetZaxis()->SetRangeUser(0,zMax);
    fwVsMultAccepted->SetStats(false);
fwVsMultAccepted->Write();
    sprintf(picName, "%s/pics/fwAccepted.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/fwAccepted.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    fwVsMultCut->Draw("colz");
    fwVsMultCut->GetZaxis()->SetRangeUser(0,zMax);
    fwVsMultCut->SetStats(false);
fwVsMultCut->Write();
    sprintf(picName, "%s/pics/fwCut.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/fwCut.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring7_9VsMultBefore->Draw("colz");
    ring7_9VsMultBefore->GetZaxis()->SetRangeUser(0,zMax);
    ring7_9VsMultBefore->SetStats(false);
ring7_9VsMultBefore->Write();
    sprintf(picName, "%s/pics/ring7_9Before.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring7_9Before.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring7_9VsMultAccepted->Draw("colz");
    ring7_9VsMultAccepted->GetZaxis()->SetRangeUser(0,zMax);
    ring7_9VsMultAccepted->SetStats(false);
ring7_9VsMultAccepted->Write();
    sprintf(picName, "%s/pics/ring7_9Accepted.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring7_9Accepted.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring7_9VsMultCut->Draw("colz");
    ring7_9VsMultCut->GetZaxis()->SetRangeUser(0,zMax);
    ring7_9VsMultCut->SetStats(false);
ring7_9VsMultCut->Write();
    sprintf(picName, "%s/pics/ring7_9Cut.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring7_9Cut.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring1_6VsMultBefore->Draw("colz");
    ring1_6VsMultBefore->GetZaxis()->SetRangeUser(0,zMax);
    ring1_6VsMultBefore->SetStats(false);
ring1_6VsMultBefore->Write();
    sprintf(picName, "%s/pics/ring1_6Before.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring1_6Before.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring1_6VsMultAccepted->Draw("colz");
    ring1_6VsMultAccepted->GetZaxis()->SetRangeUser(0,zMax);
    ring1_6VsMultAccepted->SetStats(false);
ring1_6VsMultAccepted->Write();
    sprintf(picName, "%s/pics/ring1_6Accepted.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring1_6Accepted.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    canv = new TCanvas();
    canv->SetLogz();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    ring1_6VsMultCut->Draw("colz");
    ring1_6VsMultCut->GetZaxis()->SetRangeUser(0,zMax);
    ring1_6VsMultCut->SetStats(false);
ring1_6VsMultCut->Write();
    sprintf(picName, "%s/pics/ring1_6Cut.png", outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/ring1_6Cut.C", outputdir);
    canv->SaveAs(picName);
    delete canv;
    delete leg;
    for (int i=eWallRandomA, j=0; i<=eWallRing1_6RandomA; i+=2, j++) {
        canv = new TCanvas();
        canv->SetLogz();
        hRandomQwAVsQwB[j]->Draw("colz");
        hRandomQwAVsQwB[j]->SetStats(false);
        GetSubEventTag(i, subName1);
        sprintf(picName, "%s/pics/QwQw%s.png", outputdir, subName1);
        canv->SaveAs(picName);
        sprintf(picName, "%s/pics/QwQw%s.C", outputdir, subName1);
        canv->SaveAs(picName);
        delete canv;
    }

    canv = new TCanvas();
    leg = new TLegend(0.7,0.7,0.9,0.9);
    //hNTracksBefore->SetStats(false);
    //hNTracksAccepted->SetStats(false);
    //hNTracksCut->SetStats(false);
    hNTracksBefore->Draw();
hNTracksBefore->Write();
    hNTracksAccepted->SetLineColor(kGreen);
    hNTracksAccepted->SetMarkerColor(kGreen);
    hNTracksAccepted->Draw("same");
hNTracksAccepted->Write();
    hNTracksCut->SetLineColor(kRed);
    hNTracksCut->SetMarkerColor(kRed);
    hNTracksCut->Draw("same");
hNTracksCut->Write();
    leg->AddEntry(hNTracksBefore, "Before cut", "lp");
    leg->AddEntry(hNTracksAccepted, "Accepted", "lp");
    leg->AddEntry(hNTracksCut, "Cut out", "lp");
    leg->Draw("same");
    sprintf(picName, "%s/pics/nTracks.png",outputdir);
    canv->SaveAs(picName);
    sprintf(picName, "%s/pics/nTracks.C",outputdir);
    canv->SaveAs(picName); 
    delete canv;
    delete leg; 
	TreeFile->Close();	  
}
