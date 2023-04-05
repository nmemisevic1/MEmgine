#include "ViewportWidget.h"
#include <QtWidgets/QPushButton>

struct vec3
{
	float x, y, z;
};

struct Vertex
{
	vec3 position;
    vec3 color;
};

ViewportWidget::ViewportWidget(QWidget* parent)
    : QWidget(parent)
{
    mGraphicsEngine = GraphicsEngine::getInstance();
    mGraphicsEngine->init();
    mSwapChain = mGraphicsEngine->createSwapChain();
    mSwapChain->init((HWND)this->winId(), 800, 600);

    Vertex list[] = {
        {-0.5f,-0.5f,0.0f,   0,0,0}, // POS1
        {-0.5f,0.5f,0.0f,    1,1,0}, // POS2
        { 0.5f,-0.5f,0.0f,   0,0,1},// POS2
        { 0.5f,0.5f,0.0f,    1,1,1}
    };
    
    mVertexBuffer = mGraphicsEngine->createVertexBuffer();
    UINT sizeList = ARRAYSIZE(list);
    
    
    void* shaderByteCode = nullptr;
    size_t sizeShader = 0;
    mGraphicsEngine->compileVertexShader(L"VertexShader.hlsl", "vsmain", &shaderByteCode, &sizeShader);
    mVertexShader = mGraphicsEngine->createVertexShader(shaderByteCode, sizeShader);
    mVertexBuffer->load(list, sizeof(Vertex), sizeList, shaderByteCode, sizeShader);

    mGraphicsEngine->releaseCompiledShader();

    mGraphicsEngine->compilePixelShader(L"PixelShader.hlsl", "psmain", &shaderByteCode, &sizeShader);
    mPixelShader = mGraphicsEngine->createPixelShader(shaderByteCode, sizeShader);

    mGraphicsEngine->releaseCompiledShader();
}

ViewportWidget::~ViewportWidget()
{
    mSwapChain->release();
    mGraphicsEngine->release();
    mVertexBuffer->release();
    mVertexShader->release();
    mPixelShader->release();

}

void ViewportWidget::updateViewport()
{
    renderViewport();
}

void ViewportWidget::paintEvent(QPaintEvent* event)
{
    renderViewport();
}

void ViewportWidget::resizeEvent(QResizeEvent* event)
{
    //QWidget::resizeEvent(event);
    renderViewport();
}

void ViewportWidget::showEvent(QShowEvent* event)
{
    renderViewport();
}

void ViewportWidget::tabletEvent(QTabletEvent* event)
{
    renderViewport();
}

void ViewportWidget::wheelEvent(QWheelEvent* event)
{
    renderViewport();
}

void ViewportWidget::actionEvent(QActionEvent* event)
{
    renderViewport();
}

void ViewportWidget::changeEvent(QEvent* event)
{
    renderViewport();
}

void ViewportWidget::closeEvent(QCloseEvent* event)
{
    renderViewport();
}

void ViewportWidget::contextMenuEvent(QContextMenuEvent* event)
{
    renderViewport();
}

void ViewportWidget::dragEnterEvent(QDragEnterEvent* event)
{
    renderViewport();
}

void ViewportWidget::dragLeaveEvent(QDragLeaveEvent* event)
{
    renderViewport();
}

void ViewportWidget::dragMoveEvent(QDragMoveEvent* event)
{
    QWidget::dragMoveEvent(event);
    renderViewport();
}

void ViewportWidget::dropEvent(QDropEvent* event)
{
    renderViewport();
}

void ViewportWidget::enterEvent(QEnterEvent* event)
{
    renderViewport();
}

void ViewportWidget::focusInEvent(QFocusEvent* event)
{
    renderViewport();
}

bool ViewportWidget::focusNextPrevChild(bool next)
{
    renderViewport();
    return false;
}

void ViewportWidget::focusOutEvent(QFocusEvent* event)
{
    renderViewport();
}

void ViewportWidget::hideEvent(QHideEvent* event)
{
    renderViewport();
}

void ViewportWidget::inputMethodEvent(QInputMethodEvent* event)
{
    renderViewport();
}

void ViewportWidget::keyPressEvent(QKeyEvent* event)
{
    renderViewport();
}

void ViewportWidget::keyReleaseEvent(QKeyEvent* event)
{
    renderViewport();
}

void ViewportWidget::leaveEvent(QEvent* event)
{
    renderViewport();
}

void ViewportWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    renderViewport();
}

void ViewportWidget::mouseMoveEvent(QMouseEvent* event)
{
    renderViewport();
}

void ViewportWidget::mousePressEvent(QMouseEvent* event)
{
    renderViewport();
}

void ViewportWidget::mouseReleaseEvent(QMouseEvent* event)
{
    renderViewport();
}

void ViewportWidget::moveEvent(QMoveEvent* event)
{
    QWidget::moveEvent(event);
}

bool ViewportWidget::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    return false;
}

void ViewportWidget::renderViewport()
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    RECT rc;
    GetClientRect((HWND)this->winId(), &rc);
    
    mGraphicsEngine->getImmediateDeviceContext()->setViewportSize(800, 600);
    
    mGraphicsEngine->getImmediateDeviceContext()->setVertexShader(mVertexShader);
    mGraphicsEngine->getImmediateDeviceContext()->setPixelShader(mPixelShader);

    mGraphicsEngine->getImmediateDeviceContext()->setVertexBuffer(mVertexBuffer);
    mGraphicsEngine->getImmediateDeviceContext()->drawTriangleStrip(mVertexBuffer->getSizeVertexList(), 0);


    mSwapChain->present(false);


}