#include "ViewportWidget.h"
#include <QtWidgets/QPushButton>

struct vec3
{
	float x, y, z;
};

struct Vertex
{
	vec3 position;
	vec3 position1;
    vec3 color;
    vec3 color1;
};

__declspec(align(16))
struct constant
{
    float m_angle;
};



ViewportWidget::ViewportWidget(QWidget* parent)
    : QWidget(parent)
{
    mGraphicsEngine = GraphicsEngine::getInstance();
    mGraphicsEngine->init();
    mSwapChain = mGraphicsEngine->createSwapChain();
    mSwapChain->init((HWND)this->winId(), 800, 600);

    Vertex list[] = {
        //X - Y - Z
        {-0.5f,-0.5f,0.0f,    -0.32f,-0.11f,0.0f,   0,0,0,  0,1,0 }, // POS1
        {-0.5f,0.5f,0.0f,     -0.11f,0.78f,0.0f,    1,1,0,  0,1,1 }, // POS2
        { 0.5f,-0.5f,0.0f,     0.75f,-0.73f,0.0f,   0,0,1,  1,0,0 },// POS2
        { 0.5f,0.5f,0.0f,      0.88f,0.77f,0.0f,    1,1,1,  0,0,1 }
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

    

    mConstantBuffer = mGraphicsEngine->createConstantBuffer();
    constant cc;
    cc.m_angle = 0;
    mConstantBuffer->load(&cc, sizeof(constant));

    mTimer.start();

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
    
    unsigned long new_time = 0;
    if (m_old_time)
        new_time = mTimer.elapsed() - m_old_time;
    m_delta_time = new_time / 1000.0f;
    m_old_time = mTimer.elapsed();
    m_angle += 1.57f * m_delta_time;
    constant cc;
    cc.m_angle = m_angle;
    
    mConstantBuffer->update(mGraphicsEngine->getImmediateDeviceContext(), &cc);

    mGraphicsEngine->getImmediateDeviceContext()->setConstantBuffer(mVertexShader, mConstantBuffer);
    mGraphicsEngine->getImmediateDeviceContext()->setConstantBuffer(mPixelShader, mConstantBuffer);






    mGraphicsEngine->getImmediateDeviceContext()->setVertexShader(mVertexShader);
    mGraphicsEngine->getImmediateDeviceContext()->setPixelShader(mPixelShader);

    mGraphicsEngine->getImmediateDeviceContext()->setVertexBuffer(mVertexBuffer);
    mGraphicsEngine->getImmediateDeviceContext()->drawTriangleStrip(mVertexBuffer->getSizeVertexList(), 0);


    mSwapChain->present(false);


}