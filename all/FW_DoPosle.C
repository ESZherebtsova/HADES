{
//=========Macro generated from canvas: fFW/
//=========  (Wed Nov 22 13:59:16 2017) by ROOT version5.34/14
   TCanvas *fFW = new TCanvas("fFW", "",65,52,700,500);
   fFW->Range(-1875,-2.748352,16875,1.724871);
   fFW->SetFillColor(0);
   fFW->SetBorderMode(0);
   fFW->SetBorderSize(2);
   fFW->SetLogy();
   fFW->SetFrameBorderMode(0);
   fFW->SetFrameBorderMode(0);
   
   TH1F *FW = new TH1F("FW","FW",1500,0,15000);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("FW");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 0      ");
   text = ptstats->AddText("Mean  =      0");
   text = ptstats->AddText("RMS   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   FW->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(FW);
   FW->SetLineColor(2);
   FW->GetXaxis()->SetTitle("FW charge, [GeV]");
   FW->GetXaxis()->SetLabelFont(42);
   FW->GetXaxis()->SetTitleSize(0.06);
   FW->GetXaxis()->SetTitleFont(42);
   FW->GetYaxis()->SetTitle("N_{events}");
   FW->GetYaxis()->SetLabelFont(42);
   FW->GetYaxis()->SetTitleSize(0.06);
   FW->GetYaxis()->SetTitleFont(42);
   FW->GetZaxis()->SetLabelFont(42);
   FW->GetZaxis()->SetLabelSize(0.035);
   FW->GetZaxis()->SetTitleSize(0.035);
   FW->GetZaxis()->SetTitleFont(42);
   FW->Draw("");
   
   TH1F *FW_NoCuts = new TH1F("FW_NoCuts","FW_NoCuts",300,0,30000);
   FW_NoCuts->SetLineColor(4);
   FW_NoCuts->GetXaxis()->SetLabelFont(42);
   FW_NoCuts->GetXaxis()->SetLabelSize(0.035);
   FW_NoCuts->GetXaxis()->SetTitleSize(0.035);
   FW_NoCuts->GetXaxis()->SetTitleFont(42);
   FW_NoCuts->GetYaxis()->SetLabelFont(42);
   FW_NoCuts->GetYaxis()->SetLabelSize(0.035);
   FW_NoCuts->GetYaxis()->SetTitleSize(0.035);
   FW_NoCuts->GetYaxis()->SetTitleFont(42);
   FW_NoCuts->GetZaxis()->SetLabelFont(42);
   FW_NoCuts->GetZaxis()->SetLabelSize(0.035);
   FW_NoCuts->GetZaxis()->SetTitleSize(0.035);
   FW_NoCuts->GetZaxis()->SetTitleFont(42);
   FW_NoCuts->Draw("same");
   
   TLegend *leg = new TLegend(0.2,0.15,0.6,0.4,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.03);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("FW_NoCuts","Before cuts","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("FW","After cuts","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.4634195,0.94,0.5365805,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("FW");
   pt->Draw();
   fFW->Modified();
   fFW->cd();
   fFW->SetSelected(fFW);
}
