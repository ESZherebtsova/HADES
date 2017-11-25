{
//=========Macro generated from canvas: fFW_VertexZ_NoCuts/
//=========  (Thu Nov 16 23:59:09 2017) by ROOT version5.34/14
   TCanvas *fFW_VertexZ_NoCuts = new TCanvas("fFW_VertexZ_NoCuts", "",65,52,700,500);
   fFW_VertexZ_NoCuts->Range(-92.5,-1875,32.5,16875);
   fFW_VertexZ_NoCuts->SetFillColor(0);
   fFW_VertexZ_NoCuts->SetBorderMode(0);
   fFW_VertexZ_NoCuts->SetBorderSize(2);
   fFW_VertexZ_NoCuts->SetLogz();
   fFW_VertexZ_NoCuts->SetFrameBorderMode(0);
   fFW_VertexZ_NoCuts->SetFrameBorderMode(0);
   
   TH2F *FW_VertexZ_NoCuts = new TH2F("FW_VertexZ_NoCuts","",1000,-80,20,150,0,15000);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.695,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("FW_VertexZ_NoCuts");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean x =      0");
   text = ptstats->AddText("Mean y =      0");
   text = ptstats->AddText("RMS x =      0");
   text = ptstats->AddText("RMS y =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   FW_VertexZ_NoCuts->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(FW_VertexZ_NoCuts);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
   FW_VertexZ_NoCuts->SetLineColor(ci);
   FW_VertexZ_NoCuts->GetXaxis()->SetTitle("z_{vertex}, [mm]");
   FW_VertexZ_NoCuts->GetXaxis()->SetLabelFont(42);
   FW_VertexZ_NoCuts->GetXaxis()->SetTitleSize(0.06);
   FW_VertexZ_NoCuts->GetXaxis()->SetTitleFont(42);
   FW_VertexZ_NoCuts->GetYaxis()->SetTitle("FW charge, [GeV]");
   FW_VertexZ_NoCuts->GetYaxis()->SetLabelFont(42);
   FW_VertexZ_NoCuts->GetYaxis()->SetTitleSize(0.06);
   FW_VertexZ_NoCuts->GetYaxis()->SetTitleFont(42);
   FW_VertexZ_NoCuts->GetZaxis()->SetLabelFont(42);
   FW_VertexZ_NoCuts->GetZaxis()->SetLabelSize(0.035);
   FW_VertexZ_NoCuts->GetZaxis()->SetTitleSize(0.035);
   FW_VertexZ_NoCuts->GetZaxis()->SetTitleFont(42);
   FW_VertexZ_NoCuts->Draw("COLZ");
   fFW_VertexZ_NoCuts->Modified();
   fFW_VertexZ_NoCuts->cd();
   fFW_VertexZ_NoCuts->SetSelected(fFW_VertexZ_NoCuts);
}
