{
//=========Macro generated from canvas: fFW_VertexZ/
//=========  (Thu Nov 16 23:59:15 2017) by ROOT version5.34/14
   TCanvas *fFW_VertexZ = new TCanvas("fFW_VertexZ", "",65,52,700,500);
   fFW_VertexZ->Range(-92.5,-1875,32.5,16875);
   fFW_VertexZ->SetFillColor(0);
   fFW_VertexZ->SetBorderMode(0);
   fFW_VertexZ->SetBorderSize(2);
   fFW_VertexZ->SetLogz();
   fFW_VertexZ->SetFrameBorderMode(0);
   fFW_VertexZ->SetFrameBorderMode(0);
   
   TH2F *FW_VertexZ = new TH2F("FW_VertexZ","",1000,-80,20,150,0,15000);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("FW_VertexZ");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   FW_VertexZ->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(FW_VertexZ);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   FW_VertexZ->SetLineColor(ci);
   FW_VertexZ->GetXaxis()->SetTitle("z_{vertex}, [mm]");
   FW_VertexZ->GetXaxis()->SetLabelFont(42);
   FW_VertexZ->GetXaxis()->SetTitleSize(0.06);
   FW_VertexZ->GetXaxis()->SetTitleFont(42);
   FW_VertexZ->GetYaxis()->SetTitle("FW charge, [GeV]");
   FW_VertexZ->GetYaxis()->SetLabelFont(42);
   FW_VertexZ->GetYaxis()->SetTitleSize(0.06);
   FW_VertexZ->GetYaxis()->SetTitleFont(42);
   FW_VertexZ->GetZaxis()->SetLabelFont(42);
   FW_VertexZ->GetZaxis()->SetLabelSize(0.035);
   FW_VertexZ->GetZaxis()->SetTitleSize(0.035);
   FW_VertexZ->GetZaxis()->SetTitleFont(42);
   FW_VertexZ->Draw("COLZ");
   fFW_VertexZ->Modified();
   fFW_VertexZ->cd();
   fFW_VertexZ->SetSelected(fFW_VertexZ);
}
