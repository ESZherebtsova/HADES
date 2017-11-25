{
//=========Macro generated from canvas: fMultTOFRPC_FW_No/
//=========  (Fri Nov 17 00:00:03 2017) by ROOT version5.34/14
   TCanvas *fMultTOFRPC_FW_No = new TCanvas("fMultTOFRPC_FW_No", "",65,52,700,500);
   fMultTOFRPC_FW_No->Range(-31.25,-1875,281.25,16875);
   fMultTOFRPC_FW_No->SetFillColor(0);
   fMultTOFRPC_FW_No->SetBorderMode(0);
   fMultTOFRPC_FW_No->SetBorderSize(2);
   fMultTOFRPC_FW_No->SetLogz();
   fMultTOFRPC_FW_No->SetFrameBorderMode(0);
   fMultTOFRPC_FW_No->SetFrameBorderMode(0);
   
   TH2F *MultTOFRPC_FW_No = new TH2F("MultTOFRPC_FW_No","",250,0,250,150,0,15000);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("MultTOFRPC_FW_No");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   MultTOFRPC_FW_No->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(MultTOFRPC_FW_No);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   MultTOFRPC_FW_No->SetLineColor(ci);
   MultTOFRPC_FW_No->GetXaxis()->SetTitle("TOF+RPC hits");
   MultTOFRPC_FW_No->GetXaxis()->SetLabelFont(42);
   MultTOFRPC_FW_No->GetXaxis()->SetTitleSize(0.06);
   MultTOFRPC_FW_No->GetXaxis()->SetTitleFont(42);
   MultTOFRPC_FW_No->GetYaxis()->SetTitle("FW charge, [GeV]");
   MultTOFRPC_FW_No->GetYaxis()->SetLabelFont(42);
   MultTOFRPC_FW_No->GetYaxis()->SetTitleSize(0.06);
   MultTOFRPC_FW_No->GetYaxis()->SetTitleFont(42);
   MultTOFRPC_FW_No->GetZaxis()->SetLabelFont(42);
   MultTOFRPC_FW_No->GetZaxis()->SetLabelSize(0.035);
   MultTOFRPC_FW_No->GetZaxis()->SetTitleSize(0.035);
   MultTOFRPC_FW_No->GetZaxis()->SetTitleFont(42);
   MultTOFRPC_FW_No->Draw("COLZ");
   fMultTOFRPC_FW_No->Modified();
   fMultTOFRPC_FW_No->cd();
   fMultTOFRPC_FW_No->SetSelected(fMultTOFRPC_FW_No);
}
