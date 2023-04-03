#include "ViewportWidget.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include <QtWidgets/QPushButton>

ViewportWidget::ViewportWidget(QWidget* parent)
    : QWidget(parent)
{
    mGraphicsEngine = GraphicsEngine::getInstance();
    mGraphicsEngine->init();
    mSwapChain = mGraphicsEngine->createSwapChain();
    mSwapChain->init((HWND)this->winId(), 800, 600);

    QPushButton* simpleButton = new QPushButton("Click me", nullptr);
    simpleButton->setGeometry(30, 30, 100, 30);
}

ViewportWidget::~ViewportWidget()
{
    mSwapChain->release();
    mGraphicsEngine->release();
}

void ViewportWidget::updateViewport(){
	mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::paintEvent(QPaintEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::showEvent(QShowEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::tabletEvent(QTabletEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::wheelEvent(QWheelEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::actionEvent(QActionEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::changeEvent(QEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::closeEvent(QCloseEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::contextMenuEvent(QContextMenuEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::dragEnterEvent(QDragEnterEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::dragLeaveEvent(QDragLeaveEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::dragMoveEvent(QDragMoveEvent* event)
{
    QWidget::dragMoveEvent(event);
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::dropEvent(QDropEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::enterEvent(QEnterEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::focusInEvent(QFocusEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

bool ViewportWidget::focusNextPrevChild(bool next)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
    return false;
}

void ViewportWidget::focusOutEvent(QFocusEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::hideEvent(QHideEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::inputMethodEvent(QInputMethodEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::keyPressEvent(QKeyEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::keyReleaseEvent(QKeyEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::leaveEvent(QEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::mouseMoveEvent(QMouseEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::mousePressEvent(QMouseEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::mouseReleaseEvent(QMouseEvent* event)
{
    mGraphicsEngine->getImmediateDeviceContext()->clearRenderTargetColor(this->mSwapChain, 0.7f, 0.7f, 0.7f, 1.0f);
    mSwapChain->present(false);
}

void ViewportWidget::moveEvent(QMoveEvent* event)
{
    QWidget::moveEvent(event);
}

bool ViewportWidget::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    return false;
}
