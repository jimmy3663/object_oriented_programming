
// MFCApplication1View.cpp: CMFCApplication1View 클래스의 구현
//

#include "stdafx.h"


// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
   // 표준 인쇄 명령입니다.
   ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
   ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
   ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
   ON_WM_CONTEXTMENU()
   ON_WM_RBUTTONUP()
   ON_COMMAND(ID_RESET, &CMFCApplication1View::OnReset)
   ON_COMMAND(ID_FINAL, &CMFCApplication1View::OnFinal)
   ON_COMMAND(ID_1_Step, &CMFCApplication1View::On1Step)
END_MESSAGE_MAP()

// CMFCApplication1View 생성/소멸

CMFCApplication1View::CMFCApplication1View() noexcept
{
   // TODO: 여기에 생성 코드를 추가합니다.


}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
   // TODO: CREATESTRUCT cs를 수정하여 여기에서
   //  Window 클래스 또는 스타일을 수정합니다.

   return CView::PreCreateWindow(cs);
}

// CMFCApplication1View 그리기

void CMFCApplication1View::OnDraw(CDC* pDC)
{
   CMFCApplication1Doc* pDoc = GetDocument();
   ASSERT_VALID(pDoc);
   if (!pDoc)
      return;

   
   CString str=NULL;
   
   for (int i = 0; i < CARD_COUNT; i++) {
      m_card_image[i].Destroy();
   }

   for (int i = 1; i < CARD_COUNT; i++) {
      str.Format(L"C:\\Users\\USER\\Desktop\\객프과제\\cards\\%02d.bmp", i);
      m_card_image[i-1].Load(str);
   }

   for (int i = 0; i < CARD_COUNT-1; i++) {
      m_card_image[i].Draw(pDC->m_hDC, (i % 10) * 49, (i / 10) * 72);
   }
   
   // TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
   
   //m_card_image->ReleaseDC();
   
}


// CMFCApplication1View 인쇄


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
   AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
   // 기본적인 준비
   return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
   // TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
   // TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
   ClientToScreen(&point);
   OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
   theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 진단

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
   CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
   CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
   ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
   return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 메시지 처리기


void CMFCApplication1View::OnReset()
{
   RedrawWindow();
   // TODO: 여기에 명령 처리기 코드를 추가합니다.

}


void CMFCApplication1View::OnFinal()
{
   // TODO: 여기에 명령 처리기 코드를 추가합니다.
}

void CMFCApplication1View::On1Step()
{
   RedrawWindow();
   // TODO: 여기에 명령 처리기 코드를 추가합니다.

}