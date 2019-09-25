
// SaisieJoueurDlg.h : fichier d'en-tête
//

#pragma once
#include "afxwin.h"
#include "CJoueur.h"
#include "CPartie.h"


// boîte de dialogue CSaisieJoueurDlg
class CSaisieJoueurDlg : public CDialogEx
{
// Construction
public:
	CSaisieJoueurDlg(CWnd* pParent = NULL);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SAISIEJOUEUR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	CString joueur1;
	CString joueur2;
	CString joueur3;
	CString joueur4;
	CJoueur *lesJoueurs[4];
	CPartie *laPartie;

public:
	int testDonneur1;
	void creepartie();
	CComboBox mDonneur1;
	CComboBox mDonneur2;
	CComboBox mDonneur3;
	CComboBox mDonneur4;
	int test;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();		
	
	
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedOk();
};
