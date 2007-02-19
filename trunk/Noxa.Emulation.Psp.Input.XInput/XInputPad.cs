// ----------------------------------------------------------------------------
// PSP Player Emulation Suite
// Copyright (C) 2006 Ben Vanik (noxa)
// Licensed under the LGPL - see License.txt in the project root for details
// ----------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace Noxa.Emulation.Psp.Input.XInput
{
	class XInputPad : IInputDevice
	{
		protected IEmulationInstance _emulator;
		protected ComponentParameters _params;
		protected IntPtr _windowHandle;
		protected int _padIndex = 0;
		protected bool _isConnected;

		protected PadButtons _buttons;
		protected int _analogX;
		protected int _analogY;

		public XInputPad( IEmulationInstance emulator, ComponentParameters parameters )
		{
			//Debug.Assert( emulator != null );
			Debug.Assert( parameters != null );

			_emulator = emulator;
			_params = parameters;
		}

		public ComponentParameters Parameters
		{
			get
			{
				return _params;
			}
		}

		public IEmulationInstance Emulator
		{
			get
			{
				return _emulator;
			}
		}

		public Type Factory
		{
			get
			{
				return typeof( XInputDriver );
			}
		}

		public event EventHandler Connected;
		public event EventHandler Disconnected;

		public IntPtr WindowHandle
		{
			get
			{
				return _windowHandle;
			}
			set
			{
				_windowHandle = value;
			}
		}

		public bool IsConnected
		{
			get
			{
				return _isConnected;
			}
		}

		public int AnalogX
		{
			get
			{
				return _analogX;
			}
		}

		public int AnalogY
		{
			get
			{
				return _analogY;
			}
		}

		public PadButtons Buttons
		{
			get
			{
				return _buttons;
			}
		}

		private static NativeXInput.State _state = new NativeXInput.State();

		private NativeXInput.State GetState( int padIndex )
		{
			uint ret = NativeXInput.XInputGetState( padIndex, ref _state );
			if( ret == 0 )
				_state.IsConnected = true;
			else
				_state.IsConnected = false;

			return _state;
		}

		public void Poll()
		{
			NativeXInput.State state = this.GetState( _padIndex );
			bool wasConnected = _isConnected;
			_isConnected = state.IsConnected;
			if( _isConnected == false )
			{
				if( wasConnected == true )
				{
					EventHandler handler = this.Disconnected;
					if( handler != null )
						handler( this, EventArgs.Empty );
				}
				return;
			}

			if( ( wasConnected == false ) &&
				( _isConnected == true ) )
			{
				EventHandler handler = this.Connected;
				if( handler != null )
					handler( this, EventArgs.Empty );
			}

			PadButtons buttons = PadButtons.None;
			if( state.GamePad.AButton == true )
				buttons |= PadButtons.Cross;
			if( state.GamePad.BButton == true )
				buttons |= PadButtons.Circle;
			if( state.GamePad.XButton == true )
				buttons |= PadButtons.Square;
			if( state.GamePad.YButton == true )
				buttons |= PadButtons.Triangle;
			if( state.GamePad.StartButton == true )
				buttons |= PadButtons.Start;
			if( state.GamePad.BackButton == true )
				buttons |= PadButtons.Select;
			if( state.GamePad.UpButton == true )
				buttons |= PadButtons.DigitalUp;
			if( state.GamePad.DownButton == true )
				buttons |= PadButtons.DigitalDown;
			if( state.GamePad.LeftButton == true )
				buttons |= PadButtons.DigitalLeft;
			if( state.GamePad.RightButton == true )
				buttons |= PadButtons.DigitalRight;
			if( state.GamePad.LeftShoulderButton == true )
				buttons |= PadButtons.LeftTrigger;
			if( state.GamePad.RightShoulderButton == true )
				buttons |= PadButtons.RightTrigger;
			_buttons = buttons;
			
			int analogX = state.GamePad.LeftThumbX;
			int analogY = state.GamePad.LeftThumbY;

			if( ( analogX < NativeXInput.LeftThumbDeadZone ) &&
				( analogX > -NativeXInput.LeftThumbDeadZone ) )
				analogX = 0;
			if( ( analogY < NativeXInput.LeftThumbDeadZone ) &&
				( analogY > -NativeXInput.LeftThumbDeadZone ) )
				analogY = 0;

			_analogX = analogX;
			_analogY = analogY;
		}

		public void Cleanup()
		{
		}
	}
}