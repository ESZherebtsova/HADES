{
//=========Macro generated from canvas: c1/c1
//=========  (Thu Nov 16 00:54:04 2017) by ROOT version5.34/14
   TCanvas *c1 = new TCanvas("c1", "c1",445,103,700,500);
   c1->Range(-15,-1.082112,135,6.72871);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetLogy();
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TH1F *h = new TH1F("h","N_MDC_tracks_02_eta_04_ALL",120,0,120);
   h->SetBinContent(1,29429);
   h->SetBinContent(2,113382);
   h->SetBinContent(3,230556);
   h->SetBinContent(4,343142);
   h->SetBinContent(5,419103);
   h->SetBinContent(6,459326);
   h->SetBinContent(7,467820);
   h->SetBinContent(8,457749);
   h->SetBinContent(9,434235);
   h->SetBinContent(10,400205);
   h->SetBinContent(11,358254);
   h->SetBinContent(12,307780);
   h->SetBinContent(13,252238);
   h->SetBinContent(14,197776);
   h->SetBinContent(15,147472);
   h->SetBinContent(16,103106);
   h->SetBinContent(17,68590);
   h->SetBinContent(18,42874);
   h->SetBinContent(19,24793);
   h->SetBinContent(20,13782);
   h->SetBinContent(21,7078);
   h->SetBinContent(22,3548);
   h->SetBinContent(23,1613);
   h->SetBinContent(24,737);
   h->SetBinContent(25,271);
   h->SetBinContent(26,111);
   h->SetBinContent(27,42);
   h->SetBinContent(28,6);
   h->SetBinContent(29,8);
   h->SetBinContent(30,1);
   h->SetEntries(4885027);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("h");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 4885027");
   text = ptstats->AddText("Mean  =  7.708");
   text = ptstats->AddText("RMS   =  3.925");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   h->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(h);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   h->SetLineColor(ci);
   h->GetXaxis()->SetLabelFont(42);
   h->GetXaxis()->SetLabelSize(0.035);
   h->GetXaxis()->SetTitleSize(0.035);
   h->GetXaxis()->SetTitleFont(42);
   h->GetYaxis()->SetLabelFont(42);
   h->GetYaxis()->SetLabelSize(0.035);
   h->GetYaxis()->SetTitleSize(0.035);
   h->GetYaxis()->SetTitleFont(42);
   h->GetZaxis()->SetLabelFont(42);
   h->GetZaxis()->SetLabelSize(0.035);
   h->GetZaxis()->SetTitleSize(0.035);
   h->GetZaxis()->SetTitleFont(42);
   h->Draw("colz");
   
   TPaveText *pt = new TPaveText(0.2335345,0.9367722,0.7664655,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("N_MDC_tracks_02_eta_04_ALL");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
