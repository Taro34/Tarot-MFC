
// SaisieJoueurDlg.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "SaisieJoueur.h"
#include "SaisieJoueurDlg.h"
#include "afxdialogex.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "iostream"
#include "CPartie.h"


using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// boîte de dialogue CSaisieJoueurDlg



CSaisieJoueurDlg::CSaisieJoueurDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SAISIEJOUEUR_DIALOG, pParent)
	, joueur1(_T(""))
	, joueur2(_T(""))
	, testDonneur1(0)
	, joueur3(_T(""))
	, joueur4(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSaisieJoueurDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, joueur1);
	DDX_Text(pDX, IDC_EDIT2, joueur2);
	DDX_Text(pDX, IDC_EDIT5, testDonneur1);
	DDX_Control(pDX, IDC_COMBO2, mDonneur2);
	DDX_Control(pDX, IDC_COMBO3, mDonneur3);
	DDX_Control(pDX, IDC_COMBO4, mDonneur4);
	DDX_Text(pDX, IDC_EDIT3, joueur3);
	DDX_Text(pDX, IDC_EDIT4, joueur4);
	DDX_Control(pDX, IDC_COMBO1, mDonneur1);
}

BEGIN_MESSAGE_MAP(CSaisieJoueurDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO2, &CSaisieJoueurDlg::OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CSaisieJoueurDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CSaisieJoueurDlg::OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSaisieJoueurDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, &CSaisieJoueurDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CSaisieJoueurDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CSaisieJoueurDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CSaisieJoueurDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON1, &CSaisieJoueurDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT5, &CSaisieJoueurDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDOK, &CSaisieJoueurDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// gestionnaires de messages pour CSaisieJoueurDlg

BOOL CSaisieJoueurDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CSaisieJoueurDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CSaisieJoueurDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CSaisieJoueurDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSaisieJoueurDlg::creepartie()
{
	laPartie = new CPartie(lesJoueurs);
}

void CSaisieJoueurDlg::OnCbnSelchangeCombo1()
{
	

}

void CSaisieJoueurDlg::OnCbnSelchangeCombo2()
{

	
}


void CSaisieJoueurDlg::OnCbnSelchangeCombo3()
{
	
}


void CSaisieJoueurDlg::OnCbnSelchangeCombo4()
{
	
}

void CSaisieJoueurDlg::OnEnChangeEdit1()
{
	
}


void CSaisieJoueurDlg::OnEnChangeEdit2()
{

}


void CSaisieJoueurDlg::OnEnChangeEdit3()
{
	
}



void CSaisieJoueurDlg::OnEnChangeEdit4()
{

}


void CSaisieJoueurDlg::OnBnClickedButton1()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	UpdateData(true);
	mDonneur1.ResetContent();
	mDonneur2.ResetContent();
	mDonneur3.ResetContent();
	mDonneur4.ResetContent();
	UpdateData(false);
	lesJoueurs[0] = new CJoueur(CStringA(joueur1).GetBuffer(),0);
	lesJoueurs[1] = new CJoueur(CStringA(joueur2).GetBuffer(),0);
	lesJoueurs[2] = new CJoueur(CStringA(joueur3).GetBuffer(),0);
	lesJoueurs[3] = new CJoueur(CStringA(joueur4).GetBuffer(),0);
	for (int i = 0; i < 4; i++)
		mDonneur1.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
	for (int i = 0; i < 4; i++)
	mDonneur2.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
	for (int i = 0; i < 4; i++)
		mDonneur3.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);
	for (int i = 0; i < 4; i++)
		mDonneur4.AddString(CString(lesJoueurs[i]->lireNom().c_str()));
	UpdateData(false);


}


void CSaisieJoueurDlg::OnEnChangeEdit5()
{

}


void CSaisieJoueurDlg::OnBnClickedOk()
{
	/*creepartie(lesJoueurs);
	CDialogEx::OnOK();*/
}
