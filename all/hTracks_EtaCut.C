{
//=========Macro generated from canvas: fhTracks_EtaCut/
//=========  (Fri Nov 17 00:00:27 2017) by ROOT version5.34/14
   TCanvas *fhTracks_EtaCut = new TCanvas("fhTracks_EtaCut", "",65,52,700,500);
   fhTracks_EtaCut->Range(-15,-60575.55,135,545180);
   fhTracks_EtaCut->SetFillColor(0);
   fhTracks_EtaCut->SetBorderMode(0);
   fhTracks_EtaCut->SetBorderSize(2);
   fhTracks_EtaCut->SetLogz();
   fhTracks_EtaCut->SetFrameBorderMode(0);
   fhTracks_EtaCut->SetFrameBorderMode(0);
   
   TH1F *hTracks_EtaCut = new TH1F("hTracks_EtaCut","",120,0,120);
   hTracks_EtaCut->SetBinContent(1,26740);
   hTracks_EtaCut->SetBinContent(2,105748);
   hTracks_EtaCut->SetBinContent(3,218976);
   hTracks_EtaCut->SetBinContent(4,330566);
   hTracks_EtaCut->SetBinContent(5,407752);
   hTracks_EtaCut->SetBinContent(6,450693);
   hTracks_EtaCut->SetBinContent(7,461528);
   hTracks_EtaCut->SetBinContent(8,453387);
   hTracks_EtaCut->SetBinContent(9,431026);
   hTracks_EtaCut->SetBinContent(10,397882);
   hTracks_EtaCut->SetBinContent(11,356624);
   hTracks_EtaCut->SetBinContent(12,306515);
   hTracks_EtaCut->SetBinContent(13,251327);
   hTracks_EtaCut->SetBinContent(14,197083);
   hTracks_EtaCut->SetBinContent(15,146940);
   hTracks_EtaCut->SetBinContent(16,102755);
   hTracks_EtaCut->SetBinContent(17,68356);
   hTracks_EtaCut->SetBinContent(18,42721);
   hTracks_EtaCut->SetBinContent(19,24694);
   hTracks_EtaCut->SetBinContent(20,13731);
   hTracks_EtaCut->SetBinContent(21,7051);
   hTracks_EtaCut->SetBinContent(22,3534);
   hTracks_EtaCut->SetBinContent(23,1603);
   hTracks_EtaCut->SetBinContent(24,733);
   hTracks_EtaCut->SetBinContent(25,270);
   hTracks_EtaCut->SetBinContent(26,111);
   hTracks_EtaCut->SetBinContent(27,42);
   hTracks_EtaCut->SetBinContent(28,6);
   hTracks_EtaCut->SetBinContent(29,8);
   hTracks_EtaCut->SetBinContent(30,1);
   hTracks_EtaCut->SetEntries(4808403);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("hTracks_EtaCut");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 4808403");
   text = ptstats->AddText("Mean  =  7.759");
   text = ptstats->AddText("RMS   =  3.914");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hTracks_EtaCut->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hTracks_EtaCut);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   hTracks_EtaCut->SetLineColor(ci);
   hTracks_EtaCut->GetXaxis()->SetTitle("MDC M_{trk}");
   hTracks_EtaCut->GetXaxis()->SetLabelFont(42);
   hTracks_EtaCut->GetXaxis()->SetTitleSize(0.06);
   hTracks_EtaCut->GetXaxis()->SetTitleFont(42);
   hTracks_EtaCut->GetYaxis()->SetTitle("Count");
   hTracks_EtaCut->GetYaxis()->SetLabelFont(42);
   hTracks_EtaCut->GetYaxis()->SetTitleSize(0.06);
   hTracks_EtaCut->GetYaxis()->SetTitleFont(42);
   hTracks_EtaCut->GetZaxis()->SetLabelFont(42);
   hTracks_EtaCut->GetZaxis()->SetLabelSize(0.035);
   hTracks_EtaCut->GetZaxis()->SetTitleSize(0.035);
   hTracks_EtaCut->GetZaxis()->SetTitleFont(42);
   hTracks_EtaCut->Draw("COLZ");
   fhTracks_EtaCut->Modified();
   fhTracks_EtaCut->cd();
   fhTracks_EtaCut->SetSelected(fhTracks_EtaCut);
}
