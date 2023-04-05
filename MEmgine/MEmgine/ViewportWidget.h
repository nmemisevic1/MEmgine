#pragma once
#include <QWidget>
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"

class ViewportWidget : public QWidget
{
public:
    ViewportWidget(QWidget* parent = Q_NULLPTR);
    ~ViewportWidget();
    void updateViewport();
    
    UINT viewportWidth;
    UINT viewportHeight;
private:
    GraphicsEngine* mGraphicsEngine;
    SwapChain* mSwapChain;
    VertexBuffer* mVertexBuffer;
    VertexShader* mVertexShader;
    PixelShader* mPixelShader;

protected:
    virtual void	actionEvent(QActionEvent* event) override;
    virtual void	changeEvent(QEvent* event) override;
    virtual void	closeEvent(QCloseEvent* event) override;
    virtual void	contextMenuEvent(QContextMenuEvent* event) override;
    void	create(WId window = 0, bool initializeWindow = true, bool destroyOldWindow = true);
    void	destroy(bool destroyWindow = true, bool destroySubWindows = true);
    virtual void	dragEnterEvent(QDragEnterEvent* event) override;
    virtual void	dragLeaveEvent(QDragLeaveEvent* event) override;
    virtual void	dragMoveEvent(QDragMoveEvent* event) override;
    virtual void	dropEvent(QDropEvent* event) override;
    virtual void	enterEvent(QEnterEvent* event) override;
    virtual void	focusInEvent(QFocusEvent* event) override;

    virtual bool	focusNextPrevChild(bool next) override;
    virtual void	focusOutEvent(QFocusEvent* event) override;

    virtual void	hideEvent(QHideEvent* event) override;
    virtual void	inputMethodEvent(QInputMethodEvent* event) override;
    virtual void	keyPressEvent(QKeyEvent* event) override;
    virtual void	keyReleaseEvent(QKeyEvent* event) override;
    virtual void	leaveEvent(QEvent* event) override;
    virtual void	mouseDoubleClickEvent(QMouseEvent* event) override;
    virtual void	mouseMoveEvent(QMouseEvent* event) override;
    virtual void	mousePressEvent(QMouseEvent* event) override;
    virtual void	mouseReleaseEvent(QMouseEvent* event) override;
    virtual void	moveEvent(QMoveEvent* event) override;
    virtual bool	nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
    void renderViewport();
    virtual void	paintEvent(QPaintEvent* event) override;
    virtual void	resizeEvent(QResizeEvent* event) override;
    virtual void	showEvent(QShowEvent* event) override;
    virtual void	tabletEvent(QTabletEvent* event) override;
    virtual void	wheelEvent(QWheelEvent* event) override;

};